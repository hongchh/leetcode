class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    map<int, int> nmap;
    for (int i = 0; i < nums.size(); ++i) {
      bool find = false;
      for (int j = i+1; j < nums.size() && !find; ++j) {
        if (nums[j] > nums[i]) {
          nmap[nums[i]] = nums[j];
          find = true;
        }
      }
      if (!find) nmap[nums[i]] = -1;
    }
    vector<int> next;
    for (int j = 0; j < findNums.size(); ++j) {
      next.push_back(nmap[findNums[j]]);
    }
    return next;
  }
};