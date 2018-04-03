class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        string ans = "";
        for (int i = 0; i < nums.size(); ++i) {
        	ans += to_string(nums[i]);
        }
        while (ans[0] == '0' && ans.size() > 1) {
        	ans.erase(0, 1);
        }
        return ans;
    }
private:
	static bool comp(int a, int b) {
		string _a = to_string(a);
		string _b = to_string(b);
		return _a+_b > _b+_a;
	}
};