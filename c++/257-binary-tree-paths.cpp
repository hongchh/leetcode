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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> svec;
        if (root == NULL) return svec;
        dfs(svec, to_string(root->val), root);
        return svec;
    }
private:
    void dfs(vector<string>& svec, string path, TreeNode* root) {
        if (root->left == NULL && root->right == NULL) {
            svec.push_back(path);
            return;
        }
        if (root->left != NULL)
            dfs(svec, path+"->"+to_string(root->left->val), root->left);
        if (root->right != NULL)
            dfs(svec, path+"->"+to_string(root->right->val), root->right);
    }
};