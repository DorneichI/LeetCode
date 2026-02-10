# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        
        def sumOfLeftLeavesHelper(root, left):
            if not root:
                return 0
            elif root.left or root.right:
                return sumOfLeftLeavesHelper(root.left, True) + sumOfLeftLeavesHelper(root.right, False)
            else:
                if left:
                    return root.val
                else:
                    return 0
        
        return sumOfLeftLeavesHelper(root, False)
