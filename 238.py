class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        totalProduct = 1
        zeroCount = 0
        for i in nums:
            if i == 0:
                zeroCount += 1
                if zeroCount == 2:
                    return [0] * len(nums)
            else:
                totalProduct *= i
        
        output = []
        for i in nums:
            if zeroCount == 1 and i != 0:
                output.append(0)
            elif zeroCount == 1 and i == 0:
                output.append(totalProduct)
            else:
                output.append(totalProduct // i)
            
        return output
