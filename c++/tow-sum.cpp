/*
 * O(n)
 */
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ivec;
    map<int, int> imap;
    for (int i = 0, tmp; i < nums.size(); ++i) {
      tmp = target - nums[i];
      if (imap.find(tmp) != imap.end()) {
        ivec.push_back(imap[tmp]);
        ivec.push_back(i);
        return ivec;
      }
      imap[nums[i]] = i;
    }
  }
};