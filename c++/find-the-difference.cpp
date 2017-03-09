class Solution {
public:
  char findTheDifference(string s, string t) {
    int mark[26] = {0};
    for (int i = 0; i < t.size(); ++i) {
      mark[t[i] - 'a'] += 1;
    }
    for (int i = 0; i < s.size(); ++i) {
      mark[s[i] - 'a'] -= 1;
    }
    for (int i = 0; i < 26; ++i) {
      if (mark[i] > 0) return 'a' + i;
    }
  }
};