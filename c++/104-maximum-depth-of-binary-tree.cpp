/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int height = 0;
        dfs(root, height, 1);
        return height;
    }
private:
	void dfs(TreeNode* subRoot, int& height, int currentDepth) {
		if (subRoot == NULL) return;
		if (height < currentDepth)
			height = currentDepth;
		dfs(subRoot->left, height, currentDepth+1);
		dfs(subRoot->right, height, currentDepth+1);
	}
};