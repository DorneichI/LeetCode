class Solution:
    def search(self, nums: List[int], target: int) -> int:
        low = 0
        high = len(nums) - 1

        while low <= high:
            mid = low + (high - low) // 2
            if nums[mid] < nums[0]:
                high = mid - 1
            else:
                low = mid + 1
        smallest = low

        low = 0
        high = len(nums) - 1
        while low <= high:
            mid = low + (high - low) // 2
            if nums[(mid + smallest) % len(nums)] == target:
                return (mid + smallest) % len(nums)
            elif nums[(mid + smallest) % len(nums)] < target:
                low = mid + 1
            else:
                high = mid - 1
        return -1
