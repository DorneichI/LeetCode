class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        a = sum(nums)
        b = sum(range(len(nums) + 1))
        return b - a
        # nums.sort()
        # for i in range(len(nums)):
        #     if nums[i] != i:
        #         return i
        # return len(nums)
