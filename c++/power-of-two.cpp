class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 1)
            return false;
        vector<int> v;
        while (n > 0) {
            v.push_back(n%2);
            n /= 2;
        }
        for (int i = 0; i < v.size()-1; ++i)
            if (v[i] != 0) return false;
        return true;
    }
};