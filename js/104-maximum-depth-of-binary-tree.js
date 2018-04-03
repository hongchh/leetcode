/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var depth = 0;

var maxDepth = function(root) {
    depth = 0;
    dfs(root, 1);
    return depth;
};

function dfs(root, cur) {
    if (root === null) return;
    if (depth < cur) depth = cur;
    dfs(root.left, cur+1);
    dfs(root.right, cur+1);
}