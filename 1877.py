class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        maximum = 0
        for i in range(len(nums) // 2):
            if nums[len(nums) - i - 1] + nums[i] > maximum:
                maximum = nums[len(nums) - i - 1] + nums[i]
        return maximum
