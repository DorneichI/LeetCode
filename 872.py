# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        def leafValueSequence(root):
            if not root:
                return []
            if not root.left and not root.right:
                return [root.val]
            return leafValueSequence(root.left) + leafValueSequence(root.right)
        
        return leafValueSequence(root1) == leafValueSequence(root2)
