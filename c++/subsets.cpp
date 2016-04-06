/*
 * DFS
 */
class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        ans.clear();
        dfs(0, nums.size(), nums, vector<int>(), 0);
        return ans;
    }
private:
    vector<vector<int> > ans;
    void dfs(int currentSize, int maxSize, vector<int>& nums, vector<int> temp, int pos) {
        ans.push_back(temp);
        if (currentSize == maxSize)
            return;
        for (int i = pos; i < maxSize; ++i) {
            vector<int> temp2(temp);
            temp2.push_back(nums[i]);
            dfs(currentSize+1, maxSize, nums, temp2, i+1);
        }
    }
};