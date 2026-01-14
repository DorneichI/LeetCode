class Solution:
    def sumOfGoodNumbers(self, nums: List[int], k: int) -> int:
        sum = 0
        for i in range(len(nums)):
            if i - k < 0 and i + k >= len(nums):
                sum += nums[i]
                continue
            if i - k < 0:
                if nums[i] > nums[i + k]:
                    sum += nums[i]
                continue
            if i + k >= len(nums):
                if nums[i] > nums[i - k]:
                    sum += nums[i]
                continue
            if nums[i] > nums[i - k] and nums[i] > nums[i + k]:
                sum += nums[i]
                continue
        return sum
