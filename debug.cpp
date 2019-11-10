#include <ctime>
#include <vector>
#include <cassert>
#include <cstring>
#include <utility>
#include <fstream>
#include <iostream>
#include <algorithm>

namespace usr {
    #define noqipu
    #include "usr.h"
    #undef noqipu
}

int main() {
    std::vector<std::vector<int> > ve;
    ve.resize(20);
    const int n = 15;
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
