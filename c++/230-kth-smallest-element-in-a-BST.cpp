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
    int kthSmallest(TreeNode* root, int k) {
        int ans, cur = 1;
        bool find = false;
        traverse(root, ans, k, cur, find);
        return ans;
    }
private:
	void traverse(TreeNode* subRoot, int& ans, int& kthNode, int& currentNode, bool& find) {
		if (subRoot == NULL) return;
		traverse(subRoot->left, ans, kthNode, currentNode, find);
		if (!find && currentNode == kthNode) {
			ans = subRoot->val;
			find = true;
			return;
		}
		++currentNode;
		traverse(subRoot->right, ans, kthNode, currentNode, find);
	}
};