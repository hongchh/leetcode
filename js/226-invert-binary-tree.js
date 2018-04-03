/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var invertTree = function(root) {
    recursiveInvert(root);
    return root;
};

function recursiveInvert(root) {
    if (root === null)
        return;
    if (root.left !== null)
        recursiveInvert(root.left);
    if (root.right !== null)
        recursiveInvert(root.right);
    var temp = root.left;
    root.left = root.right;
    root.right = temp;
}