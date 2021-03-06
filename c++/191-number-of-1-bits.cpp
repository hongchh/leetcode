class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t b[32];
        for (int i = 0; i < 32; ++i) {
            b[i] = 1;
            b[i] <<= i;
        }
        int count = 0;
        for (int i = 0; i < 32; ++i) {
            count += ((n & b[i]) == 0) ? 0 : 1;
        }
        return count;
    }
};