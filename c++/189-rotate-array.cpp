class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        while (k--) {
            int temp = nums[nums.size()-1];
            nums.pop_back();
            nums.insert(nums.begin(), temp);
        }
    }
};