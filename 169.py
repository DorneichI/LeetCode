class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        table = {}
        for i in nums:
            if i in table:
                table[i] += 1
            else:
                table[i] = 1
        
        maximum = 0
        max_key = None
        for key in table:
            if table[key] > maximum:
                maximum = table[key]
                max_key = key

        return max_key
