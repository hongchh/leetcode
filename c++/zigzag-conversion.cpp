/*
 * 转成对角线形式
   0     6     2
   1   5 7   1 3   7
   2 4   8 0   4 6
   3     9     5
 */
class Solution {
public:
    string convert(string s, int numRows) {
    	if (numRows == 1) return s;
        vector<string> svec;
        for (int i = 0, j = 0; i < s.size(); ++i) {
        	string str(numRows, ' ');
        	if (j == 0) {
        		for (int k = 0; k < numRows && i < s.size(); ++i, ++k) {
        			str[k] = s[i];
        		}
        		--i;
        		svec.push_back(str);
        	} else {
        		str[numRows-1-j] = s[i];
        		svec.push_back(str);
        	}
        	++j;
        	j %= (numRows-1);
        }
        string ans = "";
        for (int i = 0; i < numRows; ++i) {
        	for (int j = 0; j < svec.size(); ++j) {
        		if (svec[j][i] != ' ') ans += svec[j][i];
        	}
        }
        return ans;
    }
};