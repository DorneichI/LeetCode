class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:        
        pivot = random.choice(nums)

        left = [x for x in nums if x < pivot]
        equal = [x for x in nums if x == pivot]
        right = [x for x in nums if x > pivot]

        if k <= len(right):
            return self.findKthLargest(right, k)
        elif k <= len(right) + len(equal):
            return pivot
        else:
            return self.findKthLargest(left, k - len(right) - len(equal))
            
        # heap = []
        # for i in nums:
        #     if len(heap) < k:
        #         heapq.heappush(heap, i)
        #     elif i > heap[0]:
        #         heapq.heapreplace(heap, i)
        # return heap[0]

