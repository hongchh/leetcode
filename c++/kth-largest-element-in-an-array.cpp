class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return find(nums, 0, nums.size()-1, k);
    }
private:
    int find(vector<int>& nums, int l, int r, int k) {
        if (l == r) return nums[l];
        int mid = div(nums, l, r);
        int i = mid-l+1;
        if (i == k)
            return nums[mid];
        if (i > k)
            return find(nums, l, mid-1, k);
        return find(nums, mid+1, r, k-i);
    }
    int div(vector<int>& nums, int l, int r) {
        int key = nums[l], empty = l;
        bool fromLeft = false;
        while (l != r) {
            if (fromLeft) {
                if (nums[l] >= key) {
                    ++l;
                } else {
                    nums[empty] = nums[l];
                    empty = l;
                    fromLeft = false;
                }
            } else {
                if (nums[r] <= key) {
                    --r;
                } else {
                    nums[empty] = nums[r];
                    empty = r;
                    fromLeft = true;
                }
            }
        }
        nums[l] = key;
        return l;
    }
};