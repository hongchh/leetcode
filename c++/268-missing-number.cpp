class Solution {
public:
    int missingNumber(vector<int>& nums) {
        double sum = 0.0;
        for (int i = 0; i < nums.size(); ++i)
            sum += nums[i];
        double _sum = nums.size();
        _sum = _sum*(_sum+1)/2;
        return _sum-sum;
    }
};