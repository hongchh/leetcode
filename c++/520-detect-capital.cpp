class Solution {
public:
  bool detectCapitalUse(string word) {
    bool case1 = true, case2 = true;
    bool case3 = (word[0] < 'A' || word[0] > 'Z') ? false : true;
    for (int i = 0; i < word.size(); ++i) {
      if (word[i] < 'A' || word[i] > 'Z') case1 = false;
      if (word[i] < 'a' || word[i] > 'z') case2 = false;
      if (i != 0 && (word[i] < 'a' || word[i] > 'z')) case3 = false;
    }
    return case1 || case2 || case3;
  }
};