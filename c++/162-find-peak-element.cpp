/*
 * 这个题目要求时间复杂度为O(log(N))，可以利用二分查找来做,
   只是这里更新搜索区间的时候不太一样：如果到mid的前一步是
   上坡而mid的下一步是下坡，那么mid即是山顶；如果mid的前一
   步和后一步都是上坡，那么山顶必然位于后半区间；如果mid的
   前一步和后一步都是下坡，那么山顶必然位于前半区间。除此之
   外，还需要处理边界问题。
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
        	int mid = (left+right)/2;
        	bool prevUp = (mid == 0) ? true : (nums[mid] > nums[mid-1]);
        	bool nextUp = (mid == nums.size()-1) ? false : (nums[mid] < nums[mid+1]);
        	if (prevUp && !nextUp)
        		return mid;
        	if (prevUp && nextUp)
        		left = mid+1;
        	else
        		right = mid-1;
        }
        return left;
    }
};
