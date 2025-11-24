/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* invertTree(struct TreeNode* root) {
    if (!root) return root;
    

    int size = 4;
    struct TreeNode** queue = malloc(size * sizeof(struct TreeNode*));
    int front = 0;
    int back = 0;

    queue[back++] = root;

    while (front < back) {
        struct TreeNode *node = queue[front++];
        struct TreeNode *tmp = node->left;
        node->left = node->right;
        node->right = tmp;

        if (back >= size - 2) {
            size *= 2;
            queue = realloc(queue, size * sizeof(struct TreeNode*));
        }
        if (node->left) queue[back++] = node->left;
        if (node->right) queue[back++] = node->right;
    }

    free(queue);
    return root;
}