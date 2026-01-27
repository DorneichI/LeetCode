class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        n = len(img1)
        maximum = 0
        for i in range(1-n, n):
            for j in range(1-n, n):
                total = 0
                for x in range(n):
                    for y in range(n):
                        if x + i >= 0 and x + i < n and y + j >= 0 and y + j < n and img1[x][y] == 1 and img2[x + i][y + j] == 1:
                            total += 1

                if total > maximum:
                    maximum = total
        return maximum
                        
