class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        ht = {}
        for i in candyType:
            ht[i] = True
        
        totalTypes = 0
        for key in ht:
            totalTypes += 1
        
        if totalTypes < len(candyType) / 2:
            return totalTypes
        return len(candyType) // 2
