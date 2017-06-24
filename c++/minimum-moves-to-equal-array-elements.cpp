class Solution {
public:
  int minMoves(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int max = nums[nums.size() - 1];
    int count = max - nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] == nums[i-1]) continue;
      count += (max - nums[i]);
    }
    return count;
  }
};