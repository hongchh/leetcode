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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return recursive_judge(root->left, root->right);
    }
private:
    bool recursive_judge(TreeNode* subRoot1, TreeNode* subRoot2) {
        if (subRoot1 == NULL && subRoot2 == NULL)
            return true;
        if ((subRoot1 == NULL && subRoot2 != NULL) ||
            (subRoot1 != NULL && subRoot2 == NULL) ||
            (subRoot1->val != subRoot2->val))
            return false;
        return recursive_judge(subRoot1->left, subRoot2->right) &&
            recursive_judge(subRoot1->right, subRoot2->left);
    }
};