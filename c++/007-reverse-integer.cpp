class Solution {
public:
    int reverse(int x) {
        int _x = (x >= 0 ? x : -x);
        long long r = 0;
        while (_x > 0) {
            r = r*10 + _x%10;
            _x /= 10;
        }
        if (r > 2147483647) return 0;
        return (x >= 0 ? r : -r);
    }
};