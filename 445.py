# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        n1 = 0
        while l1:
            n1 *= 10
            n1 += l1.val
            l1 = l1.next
        n2 = 0
        while l2:
            n2 *= 10
            n2 += l2.val
            l2 = l2.next
        
        total = n1 + n2
        output = None
        while total > 0:
            output = ListNode(total % 10, output)
            total = total // 10
        if output == None:
            return ListNode()
        return output
