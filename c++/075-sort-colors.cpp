/*
 * 左边存放0，右边存放2.两边往中间靠，中间剩下的都是1
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lastZero = -1, firstTwo = nums.size();
        for (int i = 0; i < firstTwo;) {
        	if (nums[i] == 0) {
        		swap(nums[i++], nums[++lastZero]);
        	} else if (nums[i] == 2) {
        		swap(nums[i], nums[--firstTwo]);
        	} else {
        		++i;
        	}
        }
    }
};