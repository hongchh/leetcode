/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode* root) {
        while (root != NULL && root->left != NULL) {
            TreeLinkNode* cur = root;
            while (cur != NULL) {
                cur->left->next = cur->right;
                if (cur->next != NULL)
                    cur->right->next = cur->next->left;
                cur = cur->next;
            }
            root = root->left;
        }
    }
};