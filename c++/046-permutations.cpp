/*
 * 递归回溯
 */
class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        permute(nums, 0, nums.size()-1);
        return ans;
    }
private:
	vector<vector<int> > ans;
	void permute(vector<int>& nums, int k, int m) {
		if (k == m) {
			vector<int> temp;
			for (int i = 0; i <= m; ++i)
				temp.push_back(nums[i]);
			ans.push_back(temp);
		} else {
			for (int i = k; i <= m; ++i) {
				Swap(nums[k], nums[i]);
				permute(nums, k+1, m);
				Swap(nums[k], nums[i]);
			}
		}
	}
	void Swap(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
	}
};