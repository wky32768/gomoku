#include <bits/stdc++.h>
#define int long long
#define il inline
#define For(i, a, b) for (register int i = a; i <= b; i++)
using namespace std;
int x, y, now, win1, win2;
vector<vector<int>/**/> a;

unsigned long long rnd() {
	static unsigned long long i = (19260817) ^ ((int)(time(0))), j;
	i = i * i;
	i = i / 100000;
	i = i % 10000000000;
	j = i / 100000;
	return j;
}


namespace lv0 {
	#include "temp/lv0.cpp"
}
namespace lv1 {
	#include "temp/lv1.cpp"
}
namespace lv2 {
	#include "temp/lv2.cpp"
}
namespace lv3 {
	#include "temp/lv3.cpp"	
}
namespace usr {
	#include "usr.cpp"
}

pair <int,int> run(vector<vector<int> >a,int now){
	if(usr::lvl==0) return lv0::ak(a,now);
	else if(usr::lvl==1) return lv1::ak(a,now);
	else if(usr::lvl==2) return lv2::ak(a,now);
	else if(usr::lvl==3) return lv3::ak(a,now);
}

il bool over() {
	For(i, 1, 15) For(j, 1, 15) {
		if (j + 4 <= 15) {
			if (a[i][j] != 0 && a[i][j] == a[i][j + 1] && a[i][j + 1] == a[i][j + 2] && a[i][j + 2] == a[i][j + 3] && a[i][j + 3] == a[i][j + 4])
				return 1;
		}
		if (i + 4 <= 15) {
			if (a[i][j] != 0 && a[i + 1][j] == a[i][j] && a[i + 1][j] == a[i + 2][j] && a[i + 2][j] == a[i + 3][j] && a[i + 3][j] == a[i + 4][j])
				return 1;
		}
		if (i + 4 <= 15 && j + 4 <= 15) {
			if (a[i][j] != 0 && a[i][j] == a[i + 1][j + 1] && a[i + 1][j + 1] == a[i + 2][j + 2] && a[i + 2][j + 2] == a[i + 3][j + 3] && a[i + 3][j + 3] == a[i + 4][j + 4])
				return 1;
		}
		if (i + 4 <= 15 && j - 4 >= 1) {
			if (a[i][j] != 0 && a[i][j] == a[i + 1][j - 1] && a[i + 1][j - 1] == a[i + 2][j - 2] && a[i + 2][j - 2] == a[i + 3][j - 3] && a[i + 3][j - 3] == a[i + 4][j - 4])
				return 1;
		}
	}
	return 0;
}

il void f_in(char *a) {
	freopen(a, "r", stdin);
}
il void f_out(char *a) {
	freopen(a, "w", stdout);
}

#define cl_in() fclose(stdin)
#define cl_out() fclose(stdout)

pair<int, int> ans;
il void clr(vector<vector<int>/**/> &a, int x, int y) {
	a.resize(0);
	a.resize(x);
	for (int i = 0; i < x; i++) {
		a[i].resize(0);
		a[i].resize(y);
	}
}

signed main() {
	puts("How many games do you want to play?");
	int tot;
	cin >> tot;
	f_out("log.txt");
	fclose(stdout);
	For(gg,1,tot) {
		clr(a, 18, 18);
		while (!over()) {
			int tot = 0;
			For(i,1,15) For(j,1,15) if(a[i][j]) tot++;
			if (tot >= 225) break;
			ans = run(a, 1);
			a[ans.first][ans.second] = 1;
			if (over()) {
				freopen("log.txt", "a", stdout);
				puts("AI win!");
				For(i, 1, 15) {
					For(j, 1, 15) {
						if (a[i][j] == 0) {
							putchar('_');
							putchar(' ');
						} else if (a[i][j] == 1) {
							putchar('O');
							putchar(' ');
						} else if (a[i][j] == 2) {
							putchar('X');
							putchar(' ');
						}
					}
					puts("");
				}
				win1++;
				goto L3;
			}
			tot = 0;
			For(i,1,15) For(j,1,15) if(a[i][j]) tot++;
			if (tot >= 225) break;
			ans = usr::ak(a, 2);
			a[ans.first][ans.second] = 2;
			if (over()) {
				freopen("log.txt", "a", stdout);
				puts("user win!");
				For(i, 1, 15) {
					For(j, 1, 15) {
						if (a[i][j] == 0) {
							putchar('_');
							putchar(' ');
						} else if (a[i][j] == 1) {
							putchar('O');
							putchar(' ');
						} else if (a[i][j] == 2) {
							putchar('X');
							putchar(' ');
						}
					}
					puts("");
				}
				win2++;
				goto L3;
			}
		}
		freopen("log.txt","a",stdout);
		L3:;
		cout << "Game" << gg << "/" << tot << "\n\n\n";
		cl_out();
		f_out("CON");
		cout << gg << "/" << tot << "===" << win1 << " " << win2 << '\n';
		cl_out();
	}
	freopen("log.txt", "a", stdout);
	cout << win1 << " " << win2 << "\n";
	return 0;
}
