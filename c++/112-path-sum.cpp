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
    bool hasPathSum(TreeNode* root, int sum) {
        has = false;
        dfs(root, sum, 0);
        return has;
    }
private:
    bool has;
    void dfs(TreeNode* root, int sum, int currentSum) {
        if (root == NULL) return;
        if (root->left != NULL && !has)
            dfs(root->left, sum, currentSum + root->val);
        if (root->right != NULL && !has)
            dfs(root->right, sum, currentSum + root->val);
        if (root->left == NULL && root->right == NULL && !has) {
            if (currentSum + root->val == sum) {
                has = true;
                return;
            }
        }
    }
};