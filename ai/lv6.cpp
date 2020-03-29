// 这份代码请开O2编译，否则会T!!!!!

namespace pufanyi {

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
    typedef long long LL;

#ifdef QiPu
    ofstream fout("Pu.log");
#endif

    vector<vector<int> > __ch;
    int __v;
    double clo;

    class QiPan {

            int ch[maxn][maxn];

        public:

            inline void init() {
                memset(ch, 0, sizeof(ch));
                for (int i = 1; i <= siz; ++i) {
                    for (int j = 1; j <= siz; ++j) {
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
                cerr << endl;
#ifndef noqipu
                for (int i = 1; i <= n; ++i) {
                    for (int j = 1; j <= n; ++j) {
                        cerr << ch[i][j] << ' ';
                    }
                    cerr << endl;
                }
#endif
#ifdef QiPu
                fout << endl;
                for (int i = 1; i <= n; ++i) {
                    for (int j = 1; j <= n; ++j) {
                        fout << ch[i][j] << ' ';
                    }
                    fout << endl;
                }
#endif
            }

            inline int& operator [] (const gz x) {
                return ch[x.first][x.second];
            }

            inline int* operator [] (const int x) {
                return ch[x];
            }

    } ch;

    const int fxx[] = {0, 0, 1, -1, 1, 1, -1, -1};
    const int fyy[] = {1, -1, 0, 0, -1, 1, 1, -1};
    const int dirx[] = {0, 1, 1, 1};
    const int diry[] = {1, 0, -1, 1};
    const int fan[] = {0, 2, 1};

    inline double get_fang(gz now, int ys, int dir) {
        int x = now.first + fxx[dir];
        int y = now.second + fyy[dir];
        int ans = 0;
        while (ch[x][y] == fan[ys]) {
            ans++;
            x += fxx[dir];
            y += fyy[dir];
        }
        if (ans >= 4) {
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

    inline double get(const gz now) {
        double Ans = 1;
        for (int i = 0; i < 4; ++i) {
            int x = now.first;
            int y = now.second;
            ch[now] = 1;
            double ans = 0;
            while (ch[x - dirx[i]][y - diry[i]] == 1) {
                x -= dirx[i];
                y -= diry[i];
            }
            bool flg = !ch[x - dirx[i]][y - diry[i]];
            while (ch[x][y] == 1) {
                ans++;
                x += dirx[i];
                y += diry[i];
            }
            flg &= !ch[x][y];
            if (flg) {
                ans += .5;
            }
            Ans = max(ans, Ans);
            x = now.first;
            y = now.second;
            ch[now] = 2;
            ans = 0;
            while (ch[x - dirx[i]][y - diry[i]] == 2) {
                x -= dirx[i];
                y -= diry[i];
            }
            flg = !ch[x - dirx[i]][y - diry[i]];
            while (ch[x][y] == 2) {
                ans++;
                x += dirx[i];
                y += diry[i];
            }
            flg &= !ch[x][y];
            if (flg) {
                ans += .5;
            }
            ch[now] = 0;
            Ans = max(ans, Ans);
        }
        return Ans;
    }

    inline vector<gz> getqz(unsigned lim = 0) {
        auto all = getall();
        double mx = 0;
        vector<double> xx;
        for (auto x : all) {
            xx.push_back(get(x));
            mx = max(mx, *(--xx.end()));
        }
        vector<gz> ans;
        for (unsigned i = 0; i < xx.size(); ++i) {
            if (abs(xx[i] - mx) <= .2) {
                ans.push_back(all[i]);
                xx[i] = -1;
            }
        }
        if (mx <= 3) {
            while (mx > 0 && ans.size() < lim) {
                mx = 0;
                for (auto x : xx) {
                    mx = max(mx, x);
                }
                if (mx <= 0) {
                    break;
                }
                for (unsigned i = 0; i < xx.size(); ++i) {
                    if (xx[i] == mx) {
                        ans.push_back(all[i]);
                        xx[i] = -1;
                        if (ans.size() == lim) {
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }

    inline int Get(gz now, int ys) {
        int ans = 0;
        for (int i = 0; i < 8; ++i) {
            gz noww = now;
            int nowans = 0;
            while (ch[noww] == ys) {
                nowans++;
                noww.first += fxx[i];
                noww.second += fyy[i];
            }
            ans = max(nowans, ans);
        }
        return ans;
    }

    inline int win(int my) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (!ch[i][j]) {
                    ch[i][j] = my;
                    if (Get(Gz(i, j), my) >= 5) {
                        ch[i][j] = 0;
                        return 1;
                    }
                    ch[i][j] = 0;
                }
            }
        }
        return 0;
    }

    inline int dfs2(int my, int dep) {
        if (win(my)) {
            return my;
        }
        if (!dep) {
            return 0;
        }
        auto all = getqz();
        if (!all.size()) {
            return 0;
        } else {
            auto now = all[Rnd() % all.size()];
            ch[now] = my;
            int ans = dfs2(fan[my], dep - 1);
            ch[now] = 0;
            return ans;
        }
    }

    class Table {

            static const int Sz = 8;

            struct Zt {
                LL cs;
                double qz;

                Zt (LL b = 0, double c = 0) {
                    cs = b, qz = c;
                }
            };

            map<vector<LL>, Zt> mp;

        public:

            Table() {
                ifstream fin("ai/Data/pufanyi/GuJia.data");
                LL b;
                double c;
                mp.clear();
                vector<LL> a;
                while (fin >> b >> c) {
                    a.clear();
                    for (int i = 1; i <= Sz; ++i) {
                        LL x;
                        fin >> x;
                        a.push_back(x);
                    }
                    mp[a] = Zt(b, c);
                }
                fin.close();
            }

            ~Table() {
                ofstream fout("ai/Data/pufanyi/GuJia.data");
                for (auto x : mp) {
                    if (Rnd() % (x.second.cs + 2)) {
                        fout << x.second.cs << ' ' << x.second.qz << ' ';
                        for (auto y : x.first) {
                            fout << y << ' ';
                        }
                    }
                }
                fout.close();
            }

            inline vector<LL> gethsh(int my) {
                vector<LL> ans;
                ans.clear();
                for (int i = 1; i <= Sz; ++i) {
                    LL nowx = 0;
                    for (int j = 1; j <= n; ++j) {
                        nowx *= 3;
                        if (my == 1) {
                            nowx += ch[(i << 1) - 1][j];
                        } else {
                            nowx += fan[ch[(i << 1) - 1][j]];
                        }
                    }
                    if (i != Sz) {
                        for (int j = 1; j <= n; ++j) {
                            nowx *= 3;
                            if (my == 1) {
                                nowx += ch[(i << 1) - 1][j];
                            } else {
                                nowx += fan[ch[(i << 1) - 1][j]];
                            }
                        }
                    }
                    ans.push_back(nowx);
                }
                return ans;
            }

            inline void insert(int my, double gj) {
                auto xx = gethsh(my);
                auto now = mp.find(xx);
                if (now == mp.end()) {
                    mp[xx] = Zt(1, gj);
                } else {
                    double sum = now->second.qz * now->second.cs;
                    now->second.cs++;
                    sum += gj;
                    now->second.qz = sum / now->second.cs;
                }
            }

            inline unsigned size() {
                return mp.size();
            }

            inline pair<int, double> find(int my) {
                auto now = gethsh(my);
                auto it = mp.find(now);
                if (it == mp.end()) {
                    return make_pair(0, .5);
                } else {
                    return make_pair((int) (it->second).cs, (it->second).qz);
                }
            }

    } tab;

    inline double GuJia(int my) {
        const int cs = 5;
        double ans = 0;
        for (int i = 1; i <= cs; ++i) {
            int anss = dfs2(my, 20);
            if (anss == my) {
                ans++;
            } else if (!anss) {
                ans += .5;
            }
        }
        return ans / cs;
    }

    inline double GuJia_man(int my) {
        const int cs = 50;
        double ans = 0;
        for (int i = 1; i <= cs; ++i) {
            int anss = dfs2(my, 50);
            if (anss == my) {
                ans++;
            } else if (!anss) {
                ans += .5;
            }
        }
        return ans / cs;
    }

    int yz = 0;

    inline double dfs(const int dep, int my) {
        if (win(my)) {
            return 1;
        }
        auto __ans = tab.find(my);
        if (Rnd() % (__ans.first + 1)) {
            return __ans.second;
        }
        double ans = GuJia(my);
//        cerr << "ans = " << ans << endl;
        if (ans >= .8) {
            return .05 + GuJia_man(my) * .9;
        }
        if (!dep || clock() - clo > 500) {
            yz++;
            return .05 + GuJia_man(my) * .9;
        } else {
            auto all = getqz();
            double ans = 0;
            random_shuffle(all.begin(), all.end());
            for (unsigned i = 0; i < 4 && i < all.size(); ++i) {
                ch[all[i]] = my;
                double anss = 1. - dfs(dep - 1, fan[my]);
                if (anss >= .9999999) {
                    ch[all[i]] = 0;
                    tab.insert(my, 1);
                    return 1.;
                }
                ans = max(ans, anss);
                ch[all[i]] = 0;
            }
            if (clock() - clo <= 500) {
                tab.insert(my, ans);
            }
            return ans;
        }
    }

    inline gz beat(int dep) {
        auto all = getqz(3);
        if (all.empty()) {
            return Gz(8, 8);
        }
        if (all.size() == 1u) {
            cerr << "running...(1/1)" << endl;
            return *all.begin();
        }
        double nans = 0;
        gz ans(0, 0);
        random_shuffle(all.begin(), all.end());
        int cnt = 0;
        for (auto x : all) {
            ch[x] = 1;
            clo = clock();
            double nowans = 1. - dfs(dep, 2);
            cerr << "running...(" << ++cnt << '/' << all.size() << ')' << endl;
            if (nans <= nowans) {
                nans = nowans;
                ans = x;
            }
            ch[x] = 0;
        }
        if (dep > 1 && nans < .001) {
            return beat(dep - 2);
        }
        cerr << "AI: " << nans <<  ' ' << yz << endl;
#ifdef QiPu
        fout << nans <<  ' ' << yz << endl;
#endif
        assert(!ch[ans.first][ans.second]);
        cerr << tab.size() << endl;
        return ans;
    }

    inline gz my() {
        ch.init();
        return beat(12);
    }

#undef Gz

}

const int lvl = 4;

std::pair<int, int> ak(std::vector<std::vector<int> >chessground, const int v) {
    srand((unsigned) time(0));
    pufanyi::yz = 0;
    pufanyi::__ch = chessground;
    pufanyi::__v = v;
    return pufanyi::my();
}
