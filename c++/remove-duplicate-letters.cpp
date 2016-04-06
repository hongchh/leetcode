class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<char> cv;
        int count[26] = {0};
        bool used[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            ++count[s[i]-'a'];
        }
        for (int i = 0; i < s.size(); ++i) {
            --count[s[i]-'a'];
            if (used[s[i]-'a']) continue;
            while (!cv.empty() && s[i] < cv[cv.size()-1] && count[cv[cv.size()-1]-'a'] > 0) {
                used[cv[cv.size()-1]-'a'] = false;
                cv.pop_back();
            }
            cv.push_back(s[i]);
            used[s[i]-'a'] = true;
        }
        string ans = "";
        for (int i = 0; i < cv.size(); ++i)
            ans += cv[i];
        return ans;
    }
};
