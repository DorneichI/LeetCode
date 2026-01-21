class Solution:
    def findMin(self, nums: List[int]) -> int:
        smallest = 0
        for i in range(1, len(nums)):
            if nums[i] < nums[i - 1]:
                smallest = i
                break
        return nums[smallest]
