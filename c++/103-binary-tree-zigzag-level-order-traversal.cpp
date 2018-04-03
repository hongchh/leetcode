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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;
        stack<TreeNode*> stk1, stk2;
        bool fromLeft = true;
        stk1.push(root);
        while (!(stk1.empty() && stk2.empty())) {
            vector<int> cur_level;
            if (fromLeft) {
                while (!stk1.empty()) {
                    TreeNode* sub_root = stk1.top();
                    stk1.pop();
                    cur_level.push_back(sub_root->val);
                    if (sub_root->left != NULL)
                        stk2.push(sub_root->left);
                    if (sub_root->right != NULL)
                        stk2.push(sub_root->right);
                }
            } else {
                while (!stk2.empty()) {
                    TreeNode* sub_root = stk2.top();
                    stk2.pop();
                    cur_level.push_back(sub_root->val);
                    if (sub_root->right != NULL)
                        stk1.push(sub_root->right);
                    if (sub_root->left != NULL)
                        stk1.push(sub_root->left);
                }
            }
            result.push_back(cur_level);
            fromLeft = !fromLeft;
        }
        return result;
    }
};