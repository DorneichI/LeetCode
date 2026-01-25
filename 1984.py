class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        minimum = nums[len(nums) - 1]
        for i in range(len(nums) - k + 1):
            if nums[i + k - 1] - nums[i] < minimum:
                minimum = nums[i + k - 1] - nums[i]

        return minimum
