// O(n^2) 超时。。。
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        for (int i = 1; i < length; ++i) {
            if (nums[i] == nums[i-1]) {
                --length;
                for (int j = i; j < length; ++j)
                    nums[j] = nums[j+1];
                --i;
            }
        }
        return length;
    }
};

// O(n)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i] != nums[i-1]) {
                nums[length++] = nums[i];
            }
        }
        return length;
    }
};