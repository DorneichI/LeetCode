class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        table = {}
        for i in nums:
            if i in table:
                table[i] += 1
            else:
                table[i] = 1
        
        floor = len(nums) // 3
        keys = []
        for key in table:
            if table[key] > floor:
                keys.append(key)

        return keys
