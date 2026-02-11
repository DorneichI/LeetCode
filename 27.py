class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        if len(nums) == 0:
            return 0
        i = 0
        j = len(nums) - 1
        while i < j:
            if nums[i] == val:
                while i != j and nums[j] == val:
                    j -= 1
                nums[i] = nums[j]
                nums[j] = val
            if i >= j:
                break
            i += 1
        return i + 1 if nums[i] != val else i
