class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) return ans;
        int begin = nums[0], end;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > 0 && nums[i-1] < 0 || nums[i]-nums[i-1] > 1) {
                end = nums[i-1];
                string range = "";
                if (begin == end) {
                    range += to_string(begin);
                } else {
                    range += to_string(begin);
                    range += "->";
                    range += to_string(end);
                }
                begin = nums[i];
                ans.push_back(range);
            }
        }
        if (nums[nums.size()-1] != end) {
            end = nums[nums.size()-1];
            string range = "";
            if (begin == end) {
                range += to_string(begin);
            } else {
                range += to_string(begin);
                range += "->";
                range += to_string(end);
            }
            ans.push_back(range);
        }
        return ans;
    }
};
