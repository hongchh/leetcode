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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* min = (p->val < q->val) ? p : q;
        TreeNode* max = (p->val < q->val) ? q : p;
        return find(root, min, max);
    }
private:
	TreeNode* find(TreeNode* ancestor, TreeNode* min, TreeNode* max) {
		if ((ancestor->val > min->val && ancestor->val < max->val) ||
			(ancestor == min) || (ancestor == max))
			return ancestor;
		if (ancestor->val > max->val)
			return find(ancestor->left, min, max);
		if (ancestor->val < min->val)
			return find(ancestor->right, min, max);
	}
};