#include <map>
#include <vector>
#include <fstream>

using namespace std;

static const int Sz = 8;

typedef long long LL;

struct Zt {
    LL cs;
    double qz;

    Zt (LL b = 0, double c = 0) {
        cs = b, qz = c;
    }
};

map<vector<LL>, Zt> mp;

inline void Merge(string s) {
    ifstream fin(s.data());
    LL b;
    double c;
    vector<LL> a;
    while (fin >> b >> c) {
        a.clear();
        for (int i = 1; i <= Sz; ++i) {
            LL x;
            fin >> x;
            a.push_back(x);
        }
        auto now = mp.find(a);
        if (now == mp.end()) {
            mp[a] = Zt(1, c);
        } else {
            double sum = now->second.qz * now->second.cs;
            now->second.cs += b;
            sum += c * b;
            now->second.qz = sum / now->second.cs;
        }
    }
    fin.close();
}

int main() {
    Merge("tmp/data1.data");
    Merge("tmp/data2.data");
    ofstream fout("tmp/merge.data");
    for (auto x : mp) {
        fout << x.second.cs << ' ' << x.second.qz << ' ';
        for (auto y : x.first) {
            fout << y << ' ';
        }
    }
    fout.close();
    return 0;
}
