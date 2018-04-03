class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        for (int i = 0; i < length; ++i) {
            if (nums[i] == val) {
                swap(nums[i], nums[length-1]);
                --length;
                --i;
            }
        }
        return length;
    }
};