#include <ctime>
#include <fstream>
#include <algorithm>

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

const int fxx[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int fyy[] = {1, -1, 0, 0, -1, 1, 1, -1};
const int dirx[] = {0, 1, 1, 1};
const int diry[] = {1, 0, -1, 1};

inline int zsf(int x) {
    if (x == 1) {
        return 2;
    } else if (x == 2) {
        return 1;
    } else {
        return 0;
    }
}
