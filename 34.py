class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        low = 0
        high = len(nums) - 1
        i = -1
        while low <= high:
            mid = low + (high - low) // 2
            if nums[mid] == target:
                i = mid
                break
            elif nums[mid] < target:
                low = mid + 1
            else:
                high = mid - 1
        
        if i == -1:
            return [-1, -1]
        
        low = 0
        high = i
        while low < high:
            mid = low + (high - low) // 2
            if nums[mid] == target:
                high = mid
            else:
                low = mid + 1
        left = low

        low = i
        high = len(nums) - 1
        while low < high:
            mid = math.ceil(low + (high - low) / 2)
            if nums[mid] == target:
                low = mid
            else:
                high = mid - 1
        right = high

        return [left, right]
