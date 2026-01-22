# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        nodes = [root]
        count = 0
        while len(nodes) > 0:
            node = nodes.pop()
            if node.left:
                nodes.append(node.left)
            if node.right:
                nodes.append(node.right)
            count += 1
        return count
