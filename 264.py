class Solution:
    def nthUglyNumber(self, n: int) -> int:
        heap = [1]
        count = 0
        current = 0
        while count < n:
            while heap[0] <= current:
                heapq.heappop(heap)
            current = heapq.heappop(heap)
            count += 1
            heapq.heappush(heap, current * 2)
            heapq.heappush(heap, current * 3)
            heapq.heappush(heap, current * 5)
        
        return current
