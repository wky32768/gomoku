#include <vector>
#include <utility>

namespace pufanyi {
    using namespace std;
    
    #include "basedata.h"
    #include "score.h"
    #include "chessboard.h"
    
    QiPan ch;
    
    inline pair<int, int> my(vector<std::vector<int>>chessground, const int v) {
        ch.init(chessground, v);
    }
}

std::pair<int, int> play(std::vector<std::vector<int>>chessground, const int v) {
    return pufanyi::my(chessground, v);
}
