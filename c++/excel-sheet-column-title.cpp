class Solution {
public:
    string convertToTitle(int n) {
        vector<char> v;
        while (n > 0) {
            int c = n%26;
            n /= 26;
            if (c == 0) {
                v.push_back('Z');
                --n;
            } else {
                v.push_back(c-1+'A');
            }
        }
        string ans = "";
        for (int i = v.size()-1; i >= 0; --i)
            ans += v[i];
        return ans;
    }
};