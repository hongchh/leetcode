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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<NodeRecord> stk;
        vector<int> result;
        stk.push(NodeRecord(root));
        while (!stk.empty()) {
            NodeRecord& top = stk.top();
            if (top.subRoot == 0) {
                stk.pop();
            } else if (!top.visitLeft) {
                top.visitLeft = true;
                stk.push(NodeRecord(top.subRoot->left));
            } else {
                result.push_back(top.subRoot->val);
                stk.pop();
                stk.push(NodeRecord(top.subRoot->right));
            }
        }
        return result;
    }
private:
    struct NodeRecord {
        TreeNode* subRoot;
        bool visitLeft;
        NodeRecord(TreeNode* r = 0) {
            subRoot = r;
            visitLeft = false;
        }
    };
};