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
  int getMinimumDifference(TreeNode* root) {
    vector<int> visited;
    int min;
    if (root->left != NULL) {
      min = abs(root->val - root->left->val);
    } else {
      min = abs(root->val - root->right->val);
    }
    DFS(root, visited, min);
    return min;
  }
private:
  void DFS(TreeNode* root, vector<int>& visited, int& min) {
    if (root != NULL) {
      for (int i = 0; i < visited.size(); ++i) {
        int tmp = abs(root->val - visited[i]);
        if (tmp < min) min = tmp;
      }
      visited.push_back(root->val);
      DFS(root->left, visited, min);
      DFS(root->right, visited, min);
    }
  }
};