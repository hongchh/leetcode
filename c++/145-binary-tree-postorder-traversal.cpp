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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* last_visit = NULL;
        while (!stk.empty()) {
            TreeNode* sub_root = stk.top();
            if (sub_root->left == NULL && sub_root->right == NULL
                || (last_visit != NULL && (last_visit == sub_root->left
                    || last_visit == sub_root->right))) {
                stk.pop();
                result.push_back(sub_root->val);
                last_visit = sub_root;
            } else {
                if (sub_root->right != NULL)
                    stk.push(sub_root->right);
                if (sub_root->left != NULL)
                    stk.push(sub_root->left);
            }
        }
        return result;
    }
};