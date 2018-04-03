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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathToP, pathToQ;
        bool find = false;
        pathToNode(root, p, pathToP, find);
        find = false;
        pathToNode(root, q, pathToQ, find);
        TreeNode* ancestor = root;
        for (int i = 1; pathToP[i] == pathToQ[i] && i < pathToP.size() && i < pathToQ.size(); ++i) {
        	ancestor = pathToP[i];
        }
        return ancestor;
    }
private:
	void pathToNode(TreeNode* subRoot, TreeNode* destination, vector<TreeNode*>& path, bool& find) {
		path.push_back(subRoot);
		if (subRoot == NULL) {
			find = false;
			return;
		}
		if (subRoot == destination) {
			find = true;
			return;
		}
		pathToNode(subRoot->left, destination, path, find);
		if (!find) {
			path.pop_back();
			pathToNode(subRoot->right, destination, path, find);
			if (!find)
				path.pop_back();
		}
	}
};