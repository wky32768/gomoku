#include <map>
#include <ctime>
#include <vector>
#include <cassert>
#include <cstring>
#include <utility>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

namespace usr {
#define noqipu
#include "usr.cpp"
#undef noqipu
}

int main() {
    const int n = 15;
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= n; ++j) {
//            std::cout << 0 << ' ';
//        }
//        std::cout << '\n';
//    }
    std::vector<std::vector<int> > ve;
    ve.resize(20);
    for (int i = 1; i <= n; ++i) {
        ve[i].resize(20);
        for (int j = 1; j <= n; ++j) {
            std::cin >> ve[i][j];
        }
    }
    auto ans = usr::ak(ve, 1);
    std::cerr << ans.first << ' ' << ans.second << std::endl;
    return 0;
}
