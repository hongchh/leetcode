class Solution {
public:
  string reverseString(string s) {
    string res = "";
    for (int j = s.size() - 1; j > -1; --j) {
      res += s[j];
    }
    return res;
  }
};