# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap = []
        for i in range(len(lists)):
            cpy = lists[i]
            while cpy:
                heapq.heappush(heap, (cpy.val, i))
                cpy = cpy.next
        
        if len(heap) == 0:
            return None
        
        i = heapq.heappop(heap)[1]
        root = lists[i]
        lists[i] = lists[i].next
        cpy = root

        while len(heap) > 0:
            i = heapq.heappop(heap)[1]
            cpy.next = lists[i]
            lists[i] = lists[i].next
            cpy = cpy.next

        return root
