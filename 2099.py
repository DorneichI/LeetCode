class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        for i in range(len(nums)):
            nums[i] = (i, nums[i])

        nums.sort(key=lambda x: -x[1])

        output = nums[:k]
        
        output.sort(key=lambda x: x[0])

        for i in range(k):
            output[i] = output[i][1]

        return output
