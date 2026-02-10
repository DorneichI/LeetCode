# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        tenToThe = 1
        n1 = 0
        while l1:
            n1 += tenToThe * l1.val
            tenToThe *= 10
            l1 = l1.next
        
        tenToThe = 1
        n2 = 0
        while l2:
            n2 += tenToThe * l2.val
            tenToThe *= 10
            l2 = l2.next
            
        n3 = n1 + n2
        rOutput = None
        while n3 > 0:
            rOutput = ListNode(n3 % 10, rOutput)
            n3 = n3 // 10
        output = None
        while rOutput:
            output = ListNode(rOutput.val, output)
            rOutput = rOutput.next
        if output == None:
            return ListNode()
        return output
