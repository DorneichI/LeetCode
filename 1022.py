# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        def check(root, n):
            if not root:
                return 0
            if not root.left and not root.right:
                return n * 2 + root.val
            return check(root.left, n * 2 + root.val) + check(root.right, n * 2 + root.val)
        return check(root, 0)
