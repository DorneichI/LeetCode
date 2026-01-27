class Solution:
    def pivotInteger(self, n: int) -> int:
        if n == 1:
            return 1
        
        low = n // 2
        high = n

        while low <= high:
            mid = low + (high - low) // 2

            left = sum(range(mid + 1))
            right = sum(range(mid, n + 1))
            if left == right:
                return mid
            elif left < right:
                low = mid + 1
            else:
                high = mid - 1
        return -1

            
