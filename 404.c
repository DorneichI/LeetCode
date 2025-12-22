/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumOfLeftLeavesHelper(struct TreeNode* root, int isLeft) {
    if (!root) return 0;
    if (!root->left && !root->right) {
        if (isLeft) return root->val;
        return 0;
    }
    return sumOfLeftLeavesHelper(root->left, 1) + sumOfLeftLeavesHelper(root->right, 0);
}

int sumOfLeftLeaves(struct TreeNode* root) {
    return sumOfLeftLeavesHelper(root, 0);
}
