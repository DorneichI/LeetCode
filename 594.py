class Solution:
    def findLHS(self, nums: List[int]) -> int:
        nums.sort()
        left = 0
        length = 0
        leftRight = 0
        for right in range(1, len(nums)):
            if nums[right] != nums[leftRight]:
                left = leftRight
                leftRight = right
            if nums[left] == nums[right] - 1:
                if right - left + 1 > length:
                    length = right - left + 1

        return length
            
