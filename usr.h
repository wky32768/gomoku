namespace pufanyi {

#include <ctime>
#include <queue>
#include <fstream>
#include <cassert>
#include <utility>
#include <iostream>
#include <algorithm>
#include <windows.h>

#define Gz make_pair

	using namespace std;

	const int maxn = 20;
	const int allsiz = 20;
	const int n = 15;
	const int siz = 15;
	const double dbinf = 1e9;
	const int inf = 0x3f3f3f3f;

	mt19937 Rnd(time(0));

	typedef pair<int, int> gz;

	vector<vector<int> > __ch;
	int __v;
	int ch[maxn][maxn];
	ofstream fout("Pu.log");

	inline void init() {
		memset(ch, 0, sizeof(ch));
		for (int i = 1; i < siz; ++i) {
			for (int j = 1; j < siz; ++j) {
				ch[i][j] = __ch[i][j];
			}
		}
		if (__v == 2) {
			for (int i = 1; i <= siz; ++i) {
				for (int j = 1; j <= siz; ++j) {
					if (ch[i][j] == 1) {
						ch[i][j] = 2;
					} else if (ch[i][j] == 2) {
						ch[i][j] = 1;
					}
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				fout << ch[i][j] << ' ';
			}
			fout << endl;
		}
		fout << endl;
		// Sleep(1000);
	}

	const int fxx[] = {0, 0, 1, -1, 1, 1, -1, -1};
	const int fyy[] = {1, -1, 0, 0, -1, 1, 1, -1};
	const int dirx[] = {0, 1, 1, 1};
	const int diry[] = {1, 0, -1, 1};
	const int fan[] = {0, 2, 1};

	inline double get_gong(gz now, int ys) {
		double allans = 0;
		double fj = 0;
		for (int i = 0; i < 4; ++i) {
			int x = now.first;
			int y = now.second;
			double ans = 1;
			while (ch[x - dirx[i]][y - diry[i]] == ys) {
				x -= dirx[i];
				y -= diry[i];
			}
			while (ch[x][y] == ys) {
				ans += 1;
				x += dirx[i];
				y += diry[i];
			}
			if (ans > 2.5) {
				fj += (ans - 2) * .5;
			}
			if (ans > 4.5) {
				return dbinf * dbinf * dbinf;
			}
			allans = max(ans, allans);
		}
		return allans + fj;
	}

	inline double get_fang(gz now, int ys, int dir) {
		int x = now.first + fxx[dir];
		int y = now.second + fyy[dir];
		int ans = 0;
		while (ch[x][y] == fan[ys]) {
			ans++;
			x += fxx[dir];
			y += fyy[dir];
		}
		if (ans == 4) {
			return dbinf;
		}
		return ans;
	}

	inline vector<gz> getall() {
		vector<gz> ans;
		ans.clear();
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (!ch[i][j]) {
					for (int k = 0; k < 8; ++k) {
						if (ch[i + fxx[k]][j + fyy[k]]) {
							ans.emplace_back(i, j);
							break;
						}
					}
				}
			}
		}
		return ans;
	}

	inline int getqz(const gz now, int my) {
		int allans = 0;
		for (int i = 0; i < 8; ++i) {
			int x = now.first + fxx[i];
			int y = now.second + fyy[i];
			int ans = 1;
			while (ch[x][y] == my) {
				x += fxx[i];
				y += fyy[i];
				ans++;
			}
			if (ch[x][y] == 3) {
				ans++;
			}
			allans = max(ans, allans);
		}
		return allans;
	}

	inline double GuJia(gz x, int my) {
		double gong = 0, fang = 0;
		ch[x.first][x.second] = my;
		gong = get_gong(x, my);
		for (int i = 0; i < 8; ++i) {
			fang = max(fang, get_fang(x, my, i));
		}
		double ans = gong * gong + fang * fang;
		ch[x.first][x.second] = 0;
		// cerr << "GuJia " << gong << ' ' << fang << endl;
		return ans;
	}

	inline double GuJiaall(int my) {
		double ans = 0;
		auto all = getall();
		for (auto x : all) {
			ch[x.first][x.second] = 3;
		}
		bool flg1 = false, flg2 = false, flg3 = false, flg4 = false;
		for (auto x : all) {
			int myy = getqz(x, my);
			int oth = getqz(x, fan[my]);
			if (myy >= 6) {
				flg1 = true;
			} else if (oth >= 6) {
				flg2 = true;
			} else if (myy >= 5) {
				flg3 = true;
			} else if (oth >= 5) {
				flg4 = true;
			}
			// cerr << "get " << x.first << ' ' << x.second << ' ' << myy << ' ' << oth << endl;
			ans += (double) myy * myy * myy;
			ans -= (double) oth * oth * oth;
		}
		for (auto x : all) {
			ch[x.first][x.second] = 0;
		}
		if (flg1) {
			return dbinf * dbinf * dbinf;
		} else if (flg2) {
			return -dbinf * dbinf * dbinf;
		} else if (flg3) {
			return dbinf * dbinf;
		} else if (flg4) {
			return dbinf * dbinf;
		} else {
			double ans2 = -dbinf * dbinf * dbinf;
			for (auto x : all) {
				ans2 = max(ans2, GuJia(x, my));
			}
			return ans + ans2 * ans2;
		}
	}

	inline double dfs(const int dep, const int my) {
		auto all = getall();
		double ans = -dbinf * dbinf * dbinf * dbinf * dbinf;
		if (!dep) {
			ans = GuJiaall(my);
		} else {
			vector<pair<double, gz> > ve;
			ve.clear();
			for (auto x : all) {
				double ans = -GuJia(x, my);
				ve.emplace_back(ans, x);
			}
			sort(ve.begin(), ve.end());
			for (unsigned i = 0; i < 6 && i < ve.size(); ++i) {
				gz now = ve[i].second;
				assert(!ch[now.first][now.second]);
				ch[now.first][now.second] = my;
				ans = max(ans, -dfs(dep - 1, fan[my]));
				ch[now.first][now.second] = 0;
			}
		}
		return ans;
	}

	inline gz beat() {
		// cerr << "beat" << endl;
		auto all = getall();
		if (all.empty()) {
			return Gz(8, 8);
		}
		double nans = dbinf * dbinf * dbinf;
		gz ans(0, 0);
		for (auto x : all) {
			ch[x.first][x.second] = 1;
			double nowans = dfs(0, 2);
			if (nans >= nowans) {
				nans = nowans;
				ans = x;
			}
			ch[x.first][x.second] = 0;
		}
		// cerr << "ans = " << ans.first << ' ' << ans.second << ' ' << ch[ans.first][ans.second] << endl;
		assert(!ch[ans.first][ans.second]);
		// ans.first--, ans.second--;
		return ans;
	}

	inline gz my() {
		init();
		// cerr << "hhh" << endl;
		return beat();
	}

#undef Gz

}

const int lvl = 3;

std::pair<int, int> ak(std::vector<std::vector<int> >chessground, int v) {
	pufanyi::__ch = chessground;
	pufanyi::__v = v;
	return pufanyi::my();
}
