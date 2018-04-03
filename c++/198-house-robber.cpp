class Solution {
public:
    int rob(vector<int>& nums) {
        int take_it = 0, give_up = 0, max = 0;
        for (int i = 0; i < nums.size(); ++i) {
            take_it = give_up+nums[i];
            give_up = max;
            max = take_it > give_up ? take_it : give_up;
        }
        return max;
    }
};