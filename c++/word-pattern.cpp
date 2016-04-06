class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> strs;
        str += ' ';
        string s = "";
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == ' ') {
                strs.push_back(s);
                s = "";
            } else {
                s += str[i];
            }
        }
        map<char, char> m1;
        string _pattern = "";
        char ch = 'a';
        for (int i = 0; i < pattern.size(); ++i) {
            if (m1.find(pattern[i]) == m1.end())
                m1[pattern[i]] = ch++;
            _pattern += m1[pattern[i]];
        }
        map<string, char> m2;
        string _str = "";
        ch = 'a';
        for (int i = 0; i < strs.size(); ++i) {
            if (m2.find(strs[i]) == m2.end())
                m2[strs[i]] = ch++;
            _str += m2[strs[i]];
        }
        return _pattern == _str;
    }
};