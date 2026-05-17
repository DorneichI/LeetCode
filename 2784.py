class Solution:
    def isGood(self, nums: List[int]) -> bool:
        base = len(nums) - 1
        i = 1
        while i <= base:
            while nums[i - 1] != i:
                if nums[i - 1] > base:
                    return False
                elif nums[i - 1] == nums[nums[i - 1] - 1]:
                    if nums[i - 1] != base:
                        return False
                    elif nums[base] != base:
                        tmp = nums[i - 1]
                        nums[i - 1] = nums[base]
                        nums[base] = tmp
                        continue
                if nums[i - 1] == nums[nums[i - 1] - 1]:
                    return False
                tmp = nums[i - 1]
                nums[i - 1] = nums[tmp - 1]
                nums[tmp - 1] = tmp
            i += 1
        return nums[base] == base
