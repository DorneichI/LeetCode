class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        heap = []
        for i in nums[1:]:
            if len(heap) < 2:
                heapq.heappush(heap, -i)
            elif -i > heap[0]:
                heapq.heapreplace(heap, -i)
        return -sum(heap) + nums[0]
