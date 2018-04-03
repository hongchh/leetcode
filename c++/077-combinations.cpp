/*
 * 思路: 递归填数，填入的数不能小于当前数的值，防止重复。填够K个数则回溯到上一层换数
 */
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        temp.resize(k);
        ans.clear();
        maxSize = k;
        num = n;
        dfs(0, 1);
        return ans;
    }
private:
	vector<vector<int> > ans;
	vector<int> temp;
	int maxSize;
	int num;
	void dfs(int currentSize, int pos) {
		if (currentSize == maxSize) {
			ans.push_back(temp);
			return;
		}
		for (int i = pos; i <= num; ++i) {
			temp[currentSize] = i;
			dfs(currentSize+1, i+1);
		}
	}
};