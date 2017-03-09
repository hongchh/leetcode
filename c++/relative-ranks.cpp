class Solution {
public:
  vector<string> findRelativeRanks(vector<int>& nums) {
    vector<int> tmp = nums;
    sort(tmp.begin(), tmp.end());
    map<int, int> rank;
    for (int i = 0; i < tmp.size(); ++i) {
      rank[tmp[i]] = tmp.size() - i;
    }
    vector<string> ans;
    for (int i = 0; i < nums.size(); ++i) {
      if (rank[nums[i]] == 1) {
        ans.push_back("Gold Medal");
      } else if (rank[nums[i]] == 2) {
        ans.push_back("Silver Medal");
      } else if (rank[nums[i]] == 3) {
        ans.push_back("Bronze Medal");
      } else {
        ans.push_back(int2String(rank[nums[i]]));
      }
    }
    return ans;
  }
private:
  string int2String(int i) {
    string tmp = (i == 0 ? "0" : "");
    while (i > 0) {
      tmp += (i % 10) + '0';
      i /= 10;
    }
    string str = "";
    for (int i = tmp.size() - 1; i > -1; --i) {
      str += tmp[i];
    }
    return str;
  }
};