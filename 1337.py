class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        strength = []
        for i in range(len(mat)):
            if len(strength) < k:
                heapq.heappush(strength, (-sum(mat[i]), -i))
            elif (-sum(mat[i]), -i) > strength[0]:
                heapq.heapreplace(strength, (-sum(mat[i]), -i))
        output = []
        for _ in range(len(strength)):
            output.append(-heapq.heappop(strength)[1])
        return output[::-1]
