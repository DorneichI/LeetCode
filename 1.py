class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        ht = {}
        for i in range(len(nums)):
            ht[nums[i]] = i
        for i in range(len(nums)):
            if (target - nums[i]) in ht and i is not ht[target - nums[i]]:
                return [ht[target - nums[i]], i]
