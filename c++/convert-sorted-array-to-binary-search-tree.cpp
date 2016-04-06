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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(0, nums.size()-1, nums);
    }
private:
    TreeNode* build(int l, int r, vector<int>& nums) {
        if (l <= r) {
            int mid = (l+r)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = build(l, mid-1, nums);
            root->right = build(mid+1, r, nums);
            return root;
        } else {
            return NULL;
        }
    }
};