/*
 * http://yucoding.blogspot.com/2013/04/leetcode-question-70-permutations-ii.html
 * 递归回溯
 */
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
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
				if (check(k, i, nums))
					continue;
				Swap(nums[k], nums[i]);
				permute(nums, k+1, m);
				Swap(nums[k], nums[i]);
			}
		}
	}
	bool check(int k, int i, vector<int>& nums) {
		for (int j = k; j < i; ++j) {
			if (nums[j] == nums[i])
				return true;
		}
		return false;
	}
	void Swap(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
	}
};