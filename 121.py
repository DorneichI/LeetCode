class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        prices.reverse()
        high = -1
        low = sys.maxsize
        maxProfit = 0
        for i in prices:
            if i > high:
                high = i
                low = i
            if i < low:
                low = i
                if high - i > maxProfit:
                    maxProfit = high - i
        
        return maxProfit
