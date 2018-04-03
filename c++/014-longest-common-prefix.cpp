class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	if (strs.size() == 0) return "";
        int minLength = strs[0].size();
        for (int i = 1; i < strs.size(); ++i) {
        	if (strs[i].size() < minLength)
        		minLength = strs[i].size();
        }
        string prefix = "";
        bool same = true;
        for (int i = 0; i < minLength && same; ++i) {
        	char c = strs[0][i];
        	for (int j = 1; j < strs.size() && same; ++j) {
        		if (strs[j][i] != c) same = false;
        	}
        	if (same) prefix += c;
        }
        return prefix;
    }
};