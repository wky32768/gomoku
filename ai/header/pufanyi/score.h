// ¹À¼Ûº¯Êı

class Score {

        int _kai[6];
        int _bi[5];

    public:

        inline int kai(int x) {
            return _kai[x];
        }

        inline int bi(int x) {
            return _bi[x];
        }

        Score() {
            _kai[0] = 0;
            _kai[1] = 10;
            _kai[2] = 100;
            _kai[3] = 1000;
            _kai[4] = 10000;
            _kai[5] = 100000;
            _bi[0] = 0;
            _bi[1] = 1;
            _bi[2] = 10;
            _bi[3] = 100;
            _bi[4] = 1000;
        }
};
