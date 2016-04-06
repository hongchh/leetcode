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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        queue<TreeNode*> nq;
        nq.push(root);
        while (!nq.empty()) {
        	int size = nq.size();
        	vector<int> currentLevel;
        	while (size--) {
        		TreeNode* front = nq.front();
        		currentLevel.push_back(front->val);
        		if (front->left != NULL)
        			nq.push(front->left);
        		if (front->right != NULL)
        			nq.push(front->right);
        		nq.pop();
        	}
        	ans.push_back(currentLevel);
        }
        return ans;
    }
};