/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    for (var i = 0, p = 0; i < nums.length; ++i) {
        if (nums[i] !== 0) {
            var temp = nums[i];
            nums[i] = nums[p];
            nums[p] = temp;
            ++p;
        }
    }
};