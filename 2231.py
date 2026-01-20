class Solution:
    def largestInteger(self, num: int) -> int:
        evens = []
        odds = []
        for c in str(num):
            if int(c) % 2 == 0:
                evens.append(-int(c))
            else:
                odds.append(-int(c))
        heapq.heapify(evens)
        heapq.heapify(odds)
        output = 0
        for c in str(num):
            output *= 10
            if int(c) % 2 == 0:
                output -= heapq.heappop(evens)
            else:
                output -= heapq.heappop(odds)
        return output
