class Solution {
public:
    int countPrimes(int n) {
        bool* mark = new bool[n];
        memset(mark, 0, sizeof(mark));
        int upper = sqrt(n);
        for (int i = 2; i <= upper; ++i) {
            if (!mark[i]) {
                for (int j = i*i; j < n; j += i)
                    mark[j] = true;
            }
        }
        int count = 0;
        for (int i = 2; i < n; ++i)
            if (!mark[i]) ++count;
        delete [] mark;
        return count;
    }
};