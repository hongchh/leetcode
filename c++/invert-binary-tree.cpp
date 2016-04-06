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
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
private:
	void invert(TreeNode* subRoot) {
		if (subRoot == NULL) return;
		if (subRoot->left != NULL)
			invert(subRoot->left);
		if (subRoot->right != NULL)
			invert(subRoot->right);
		TreeNode* temp = subRoot->left;
		subRoot->left = subRoot->right;
		subRoot->right = temp;
	}
};