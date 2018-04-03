class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = nums.size()-1;
        while (s >= 0 && nums[s] > target) --s;
        return s < 0 ? 0 : (nums[s] == target ? s : s+1);
    }
};