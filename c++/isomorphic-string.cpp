class Solution {
public:
    bool isIsomorphic(string s, string t) {
        code_s.resize(255, -1);
        code_t.resize(255, -1);
        string ss = "";
        for (int i = 0, j = 0; i < s.size(); ++i) {
        	if (code_s[s[i]] == -1)
        		code_s[s[i]] = j++;
        	ss += (code_s[s[i]] + '0');
        }
        string tt = "";
        for (int i = 0, j = 0; i < t.size(); ++i) {
        	if (code_t[t[i]] == -1)
        		code_t[t[i]] = j++;
        	tt += (code_t[t[i]] + '0');
        }
        return ss == tt;
    }
private:
	vector<int> code_s;
	vector<int> code_t;
};