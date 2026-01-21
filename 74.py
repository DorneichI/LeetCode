class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix)
        n = len(matrix[0])

        length = m * n

        low = 0
        high = length - 1
        while low <= high:
            mid = low + (high - low) // 2
            if matrix[mid // n][mid % n] == target:
                return True
            elif matrix[mid // n][mid % n] < target:
                low = mid + 1
            else:
                high = mid - 1
        return False
