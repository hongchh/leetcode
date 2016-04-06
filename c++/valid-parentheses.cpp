class Solution {
public:
    bool isValid(string s) {
        stack<char> cstk;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ')' && !cstk.empty() && cstk.top() == '(')
                cstk.pop();
            else if (s[i] == ']' && !cstk.empty() && cstk.top() == '[')
                cstk.pop();
            else if (s[i] == '}' && !cstk.empty() && cstk.top() == '{')
                cstk.pop();
            else
                cstk.push(s[i]);
        }
        return cstk.empty();
    }
};