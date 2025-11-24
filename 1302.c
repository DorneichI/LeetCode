/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct Thingy {
    int sum;
    int depth;
};

struct Thingy* deepestLeavesSumH(struct TreeNode* root, int depth) {
    struct Thingy* thingy1 = NULL;
    struct Thingy* thingy2 = NULL;
    if (root->left) {
        thingy1 = deepestLeavesSumH(root->left, depth + 1);
    }
    if (root->right) {
        thingy2 = deepestLeavesSumH(root->right, depth + 1);
    }
    if (!thingy1 && !thingy2) {
        thingy1 = malloc(sizeof(struct Thingy));
        thingy1->sum = root->val;
        thingy1->depth = depth;
        return thingy1;
    } else if (!thingy1) {
        return thingy2;
    } else if (!thingy2) {
        return thingy1;
    } else if (thingy1->depth > thingy2->depth) {
        free(thingy2);
        return thingy1;
    } else if (thingy2->depth > thingy1->depth) {
        free(thingy1);
        return thingy2;
    } else {
        thingy1->sum += thingy2->sum;
        free(thingy2);
        return thingy1;
    }
}

int deepestLeavesSum(struct TreeNode* root) {
    struct Thingy* thingy = deepestLeavesSumH(root, 0);
    int sum = thingy->sum;
    free(thingy);
    return sum;
}