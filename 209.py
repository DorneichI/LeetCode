class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        left = 0
        right = 1
        minn = 1000000
        summ = nums[left]
        while True:
            while right < len(nums) and summ < target:
                summ += nums[right]
                right += 1
            while left < right and summ - nums[left] >= target:
                summ -= nums[left]
                left += 1
            if summ >= target and right - left < minn:
                minn = right - left
            if right >= len(nums):
                break
            summ += nums[right]
            right += 1
        if minn == 1000000:
            return 0
        return minn
            
            
