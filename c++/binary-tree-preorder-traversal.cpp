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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* sub_root = stk.top();
            stk.pop();
            result.push_back(sub_root->val);
            if (sub_root->right != NULL)
                stk.push(sub_root->right);
            if (sub_root->left != NULL)
                stk.push(sub_root->left);
        }
        return result;
    }
};