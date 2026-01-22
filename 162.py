class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        low = 0
        high = len(nums) - 1

        def checkForPeak(x):
            return (x - 1 < 0 or nums[x] > nums[x - 1]) and (x + 1 >= len(nums) or nums[x] > nums[x + 1])\
        
        def leftOfPeak(x):
            return x == 0 or nums[x] < nums[x + 1]

        while low <= high:
            mid = low + (high - low) // 2
            if checkForPeak(mid):
                return mid
            elif leftOfPeak(mid):
                low = mid + 1
            else:
                high = mid - 1

        return -1
