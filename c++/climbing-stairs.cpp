class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int a = 0, b = 1;
        for (int i = 0; i < n; ++i) {
            int sum = a+b;
            a = b;
            b = sum;
        }
        return b;
    }
};