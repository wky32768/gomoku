const int lvl=3;

#include <ctime>
#include <utility>
#include <iostream>
#include <algorithm>

namespace pufanyi {

#define Gz make_pair

    using namespace std;

    const int allsiz = 20;
    const int siz = 15;

    mt19937::Rnd(time(0));

    typedef pair<int, int> gz;

    vector<vector<int> > __ch;
    int __v;
    int ch[maxn][maxn];

    inline void init() {
        for (int i = 0; i < siz; ++i) {
            for (int j = 0; j < siz; ++j) {
                ch[i + 1][j + 1] = __ch[i][j];
            }
        }
        if (v == 2) {
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
    }
    
    const int fxx[] = {0, 0, 1, -1, 1, 1, -1, -1};
    const int fyy[] = {1, -1, 0, 0, -1, 1, 1, -1};
    
    inline int getqz(int x, int y) {
        const int ys = ch[x][y];
        int ans = 0;
        for (int i = 0; i < 8; ++i) {
            int nowx = x, nowy = y;
            int nowans = 1;
            while (true) {
                nowx += fxx[i];
                nowy += fyy[i];
                if (ch[nowx][nowy] == ys) {
                    nowans++;
                } else {
                    break;
                }
            }
            ans = max(nowans, ans);
        }
        return ans;
    }
    
    const int fan[] = {0, 2, 1};
    
    inline gz pan(int yy) {
        gz ans = Gz(0, 0);
        for (int i = 1; i <= siz; ++i) {
            for (int j = 1; j <= siz; ++j) {
                if (ch[i][j] == fan[yy]) {
                    ans.first = min(ans.first, -getqz(i, j));
                } else if (ch[i][j] == yy) {
                    ans.second = max(ans.second, getqz(i, j));
                }
            }
        }
        return ans;
    }

    inline void dfs(int dep) {
    }

    inline gz my() {
        init();
    }

}

pair<int,int> ak(vector<vector<int> >chessground,int v) {
    pufanyi::__ch = chessground;
    pufanyi::__v = v;
    return pufanyi::my();
}

