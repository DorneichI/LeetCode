class Solution:
    def search(self, nums: List[int], target: int) -> int:
        smallest = 0
        for i in range(1, len(nums)):
            if nums[i] < nums[i - 1]:
                smallest = i
                break

        low = 0
        high = len(nums) - 1
        while low <= high:
            mid = low + (high - low) // 2
            if nums[(mid + smallest) % len(nums)] == target:
                return True
            elif nums[(mid + smallest) % len(nums)] < target:
                low = mid + 1
            else:
                high = mid - 1
        return False
