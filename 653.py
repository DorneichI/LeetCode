# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        ht = {}
        
        def traverse(root):
            if not root:
                return
            ht[root.val] = True
            traverse(root.left)
            traverse(root.right)
        
        traverse(root)
        for key in ht:
            if k - key != key and k - key in ht:
                return True
        return False
