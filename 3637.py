class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        phase = 0
        if nums[1] <= nums[0]:
            return False
        for i in range(2, len(nums)):
            if nums[i] == nums[i - 1]:
                return False
            if phase == 0:
                if nums[i] < nums[i - 1]:
                    phase += 1
            elif phase == 1:
                if nums[i] > nums[i - 1]:
                    phase += 1
            else:
                if nums[i] < nums[i - 1]:
                    return False
        return phase == 2
