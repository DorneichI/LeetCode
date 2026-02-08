# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def checkBalance(root):
            if not root:
                return 0
            leftBalance = checkBalance(root.left)
            rightBalance = checkBalance(root.right)
            if leftBalance < 0 or rightBalance < 0 or abs(leftBalance - rightBalance) > 1:
                return -1
            else:
                return max(leftBalance, rightBalance) + 1
        
        return checkBalance(root) >= 0
