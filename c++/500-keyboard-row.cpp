class Solution {
public:
  vector<string> findWords(vector<string>& words) {
    string lowercase[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    string uppercase[3] = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
    map<char, int> cimap;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < lowercase[i].size(); ++j) {
        cimap[lowercase[i][j]] = i;
        cimap[uppercase[i][j]] = i;
      }
    }
    vector<string> ans;
    for (int i = 0; i < words.size(); ++i) {
      bool ok = true;
      for (int j = 1; j < words[i].size(); ++j) {
        if (cimap[words[i][j]] != cimap[words[i][0]]) {
          ok = false;
          break;
        }
      }
      if (ok) ans.push_back(words[i]);
    }
    return ans;
  }
};