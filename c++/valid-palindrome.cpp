class Solution {
public:
    bool isPalindrome(string s) {
        string ss = "";
        for (int i = 0; i < s.size(); ++i) {
            if (isalpha(s[i]))
                ss += tolower(s[i]);
            if (isdigit(s[i]))
                ss += s[i];
        }
        string sss = "";
        for (int i = ss.size()-1; i >= 0; --i)
            sss += ss[i];
        return sss == ss;
    }
};