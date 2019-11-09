
namespace pufanyi {

#include <ctime>
#include <queue>
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

    inline void init() {
        memset(ch, 0, sizeof(ch));
        for (int i = 0; i < siz; ++i) {
            for (int j = 0; j < siz; ++j) {
                ch[i + 1][j + 1] = __ch[i][j];
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
        cerr << "cb = \n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cerr << ch[i][j] << ' ';
            }
            cerr << endl;
        }
        cerr << endl;
        Sleep(1000);
    }

    const int fxx[] = {0, 0, 1, -1, 1, 1, -1, -1};
    const int fyy[] = {1, -1, 0, 0, -1, 1, 1, -1};
    const int dirx[] = {0, 1, 1, 1};
    const int diry[] = {1, 0, -1, 1};
    const int fan[] = {0, 2, 1};

    inline double get_gong(gz now, int ys) {
        double allans = 0;
        double fj = 0;
//		cerr << "get_gong" << endl;
        for (int i = 0; i < 4; ++i) {
            int x = now.first;
            int y = now.second;
            double ans = 0;
//			cerr << "debug " << x << ' ' << y << endl;
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
                return dbinf * dbinf;
            }
            allans = max(ans, allans);
        }
        return allans + fj;
    }

    inline double get_fang(gz now, int ys, int dir) {
        int x = now.first + fxx[dir];
        int y = now.second + fyy[dir];
        int ans = 0;
        while (ch[x][y] == ys) {
            ans++;
            x += fxx[dir];
            y += fyy[dir];
        }
        if (ans >= 4) {
            return dbinf;
        }
        return ans;
    }

    inline double GuJia(gz x, int my) {
        double gong = 0, fang = 0;
        ch[x.first][x.second] = my;
        gong = get_gong(ans, my);
//		cerr << "Haha" << endl;
        for (int i = 0; i < 8; ++i) {
            fang = max(fang, get_fang(x, my, i));
        }
        ch[x.first][x.second] = 0;
        cerr << "GuJia " << gong << ' ' << fang << endl;
        return gong + fang * 1.5;
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

    inline double dfs(const int dep, const int my) {
//		if (!dep) {
//			cerr << "mychess ";
//			for (int i = 1; i <= n; ++i) {
//				for (int j = 1; j <= n; ++j) {
//					cerr << ch[i][j] << ' ';
//				}
//				cerr << endl;
//			}
//			cerr << endl;
//		}
//		cerr << "dfs " << dep << ' ' << my << endl;
        auto all = getall();
        double ans = -dbinf * dbinf * dbinf;
        if (!dep) {
            for (auto x : all) {
//				cerr << x.first << ' ' << x.second << '\n';
                ans = max(ans, GuJia(x, my));
            }
        } else {
            vector<pair<double, gz> > ve;
            for (auto x : all) {
                ve.emplace_back(GuJia(x, my), x);
            }
            sort(ve.begin(), ve.end(), greater<pair<double, gz> >());
            for (unsigned i = 0; i < 10 && i < ve.size(); ++i) {
                gz now = ve[i].second;
                cerr << now.first << ' ' << now.second << endl;
                assert(!ch[now.first][now.second]);
                ch[now.first][now.second] = my;
                ans = max(ans, dfs(dep - 1, fan[my]));
                ch[now.first][now.second] = 0;
            }
        }
        return -ans;
    }

    inline gz beat() {
//		cerr << "beat" << endl;
        auto all = getall();
//        for (auto x : all) {
//            cerr << "all " << x.first << ' ' << x.second << endl;
//        }
//		cerr << "beat " << all.size() << endl;
        if (all.empty()) {
//			cout << "return" << endl;
            return Gz(8, 8);
        }
        double nans = -dbinf * dbinf * dbinf;
        gz ans(0, 0);
        for (auto x : all) {
            ch[x.first][x.second] = 1;
            double nowans = dfs(0, 2);
			cerr << "nowans = " << nowans << ' ' << x.first << ' ' << x.second << endl;
            if (nans < nowans || (nans == nowans && (Rnd() & 1))) {
                nans = nowans;
                ans = x;
            }
            ch[x.first][x.second] = 0;
        }
//        cerr << "ans = " << ans.first << ' ' << ans.second << ' ' << ch[ans.first][ans.second] << endl;
        assert(!ch[ans.first][ans.second]);
        ans.first--, ans.second--;
        return ans;
    }

    inline gz my() {
        init();
//		cerr << "hhh" << endl;
        return beat();
    }

#undef Gz

}

const int lvl=4;

std::pair<int,int> ak(std::vector<std::vector<int> >chessground,int v) {
    pufanyi::__ch = chessground;
    pufanyi::__v = v;
    return pufanyi::my();
}
