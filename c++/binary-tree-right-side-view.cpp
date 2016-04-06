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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ivec;
        if (root == NULL) return ivec;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int cur = q.size();
            for (int i = 0; i < cur; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
                if (i == cur-1)
                    ivec.push_back(node->val);
            }
        }
        return ivec;
    }
};