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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            int cur_size = q.size();
            while (cur_size--) {
                TreeNode* sub_root = q.front();
                q.pop();
                level.push_back(sub_root->val);
                if (sub_root->left != NULL)
                    q.push(sub_root->left);
                if (sub_root->right != NULL)
                    q.push(sub_root->right);
            }
            result.push_back(level);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};