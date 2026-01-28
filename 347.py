class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        elements = {}
        for i in nums:
            if i in elements:
                elements[i] += 1
            else:
                elements[i] = 1
        heap = []
        for key in elements:
            if len(heap) < k:
                heapq.heappush(heap, (elements[key], key))
            elif elements[key] > heap[0][0]:
                heapq.heapreplace(heap, (elements[key], key))
        output = []
        for i, j in heap:
            output.append(j)
        return output
