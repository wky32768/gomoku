#include <cstring>
#include <iostream>

#include "basedata.h"
#include "score.h"

using namespace std;

class QiPan {

        int ch[maxn][maxn];
        int n;

    public:

        inline void fan() {
            for (int i = 1; i <= siz; ++i) {
                for (int j = 1; j <= siz; ++j) {
                    ch[i][j] = zsf(ch[i][j]);
                }
            }
        }

        inline void init(vector<vector<int>> __ch, int __v) {
            n = siz;
            memset(ch, 0, sizeof(ch));
            for (int i = 1; i <= siz; ++i) {
                for (int j = 1; j <= siz; ++j) {
                    ch[i][j] = __ch[i][j];
                }
            }
            if (__v == 2) {
                fan();
            }
        }

        inline int& operator [] (const gz x) {
            return ch[x.first][x.second];
        }

        inline int* operator [] (const int x) {
            return ch[x];
        }

        inline int _Gujia(int my) {
            int ss[maxn][maxn], xx[maxn][maxn], zz[maxn][maxn], yy[maxn][maxn];
            int zs[maxn][maxn], ys[maxn][maxn], zx[maxn][maxn], yx[maxn][maxn];
            int sf[maxn][maxn], xf[maxn][maxn], zf[maxn][maxn], yf[maxn][maxn];
            int zsf[maxn][maxn], yxf[maxn][maxn], zxf[maxn][maxn], ysf[maxn][maxn];
            memset(ss, 0, sizeof(ss)), memset(xx, 0, sizeof(xx));
            memset(zz, 0, sizeof(zz)), memset(yy, 0, sizeof(yy));
            memset(sf, 0, sizeof(sf)), memset(xf, 0, sizeof(xf));
            memset(zf, 0, sizeof(zf)), memset(yf, 0, sizeof(yf));
            memset(ss, 0, sizeof(zs)), memset(xx, 0, sizeof(ys));
            memset(zz, 0, sizeof(zx)), memset(yy, 0, sizeof(yx));
            memset(ss, 0, sizeof(zsf)), memset(xx, 0, sizeof(ysf));
            memset(zz, 0, sizeof(zxf)), memset(yy, 0, sizeof(yxf));
            if (my == 2) {
                fan();
            }
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (ch[i][j] == 1) {
                        ss[i][j] = ss[i - 1][j] + 1;
                        zz[i][j] = zz[i][j - 1] + 1;
                        zs[i][j] = zs[i - 1][j - 1] + 1;
                        ys[i][j] = ys[i - 1][j + 1] + 1;
                        sf[i][j] = sf[i - 1][j] || ch[i - 1][j] == 2 || i == 1;
                        zf[i][j] = zf[i][j - 1] || ch[i][j - 1] == 2 || j == 1;
                        zsf[i][j] = zsf[i - 1][j - 1] || ch[i - 1][j - 1] == 2 || i == 1 || j == 1;
                        ysf[i][j] = ysf[i - 1][j + 1] || ch[i - 1][j + 1] == 2 || i == 1 || j == n;
                    }
                }
            }
            for (int i = n; i; --i) {
                for (int j = n; j; --j) {
                    if (ch[i][j] == 1) {
                        xx[i][j] = xx[i + 1][j] + 1;
                        yy[i][j] = yy[i][j + 1] + 1;
                        zx[i][j] = zx[i + 1][j - 1] + 1;
                        yx[i][j] = yx[i + 1][j + 1] + 1;
                        xf[i][j] = xf[i + 1][j] || ch[i + 1][j] == 2 || i == n;
                        yf[i][j] = yf[i][j - 1] || ch[i][j + 1] == 2 || j == n;
                        zxf[i][j] = zxf[i + 1][j - 1] || ch[i + 1][j - 1] == 2 || i == n || j == 1;
                        yxf[i][j] = yxf[i + 1][j + 1] || ch[i + 1][j + 1] == 2 || i == n || j == n;
                    }
                }
            }
            int ans = 0;
            Score sc;
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (ch[i][j] == 1) {
                        int shu = ss[i][j] + xx[i][j] - 1;
                        int heng = zz[i][j] + yy[i][j] - 1;
                        int pie = ys[i][j] + zx[i][j] - 1;
                        int na = zs[i][j] + yx[i][j] - 1;
                        if (!(sf[i][j] && xf[i][j])) {
                            if (sf[i][j] || xf[i][j]) {
                                ans += sc.bi(shu);
                            } else {
                                ans += sc.kai(shu);
                            }
                        }
                        if (!(zf[i][j] && yf[i][j])) {
                            if (zf[i][j] || yf[i][j]) {
                                ans += sc.bi(heng);
                            } else {
                                ans += sc.kai(heng);
                            }
                        }
                        if (!(zsf[i][j] && yxf[i][j])) {
                            if (zsf[i][j] || yxf[i][j]) {
                                ans += sc.bi(na);
                            } else {
                                ans += sc.kai(na);
                            }
                        }
                        if (!(ysf[i][j] && zxf[i][j])) {
                            if (ysf[i][j] || zxf[i][j]) {
                                ans += sc.bi(pie);
                            } else {
                                ans += sc.kai(pie);
                            }
                        }
                    }
                }
            }
            if (my == 2) {
                fan();
            }
            return ans;
        }
        
        inline int Gujia(int my) {
            return Gujia(my) - Gujia(zsf(my));
        }

};
