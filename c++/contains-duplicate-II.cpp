class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> range;
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (i-j > k) {
                ++j;
                range.erase(range.find(nums[j-1]));
            }
            if (range.find(nums[i]) != range.end())
                return true;
            range.insert(nums[i]);
        }
        return false;
    }
};