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
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return is_balanced(root, depth);
    }
private:
    bool is_balanced(TreeNode* subRoot, int& depth) {
        if (subRoot == 0) {
            depth = 0;
            return true;
        } else {
            int leftDepth, rightDepth;
            bool leftBalanced = is_balanced(subRoot->left, leftDepth);
            bool rightBalanced = is_balanced(subRoot->right, rightDepth);
            if (leftBalanced && rightBalanced) {
                int diff = leftDepth - rightDepth;
                if (diff >= -1 && diff <= 1) {
                    depth = leftDepth > rightDepth ? leftDepth+1 : rightDepth+1;
                    return true;
                }
            }
            return false;
        }
    }
};