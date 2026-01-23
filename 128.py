class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        table = {}
        for i in nums:
            table[i] = 1

        maximum = 0
        for key in table:
            streak = 0
            if key - 1 not in table:
                streak += 1
                current = key + 1
                while current in table:
                    streak += 1
                    current += 1
                if streak > maximum:
                    maximum = streak
        
        return maximum
        
