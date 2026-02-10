class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        minCost = [sys.maxsize] * len(cost)
        minCost[0] = cost[0]
        minCost[1] = cost[1]
        
        for i in range(len(cost)):
            if i + 1 < len(cost) and minCost[i] + cost[i + 1] < minCost[i + 1]:
                minCost[i + 1] = minCost[i] + cost[i + 1]
            if i + 2 < len(cost) and minCost[i] + cost[i + 2] < minCost[i + 2]:
                minCost[i + 2] = minCost[i] + cost[i + 2]
                
        if minCost[len(cost) - 1] < minCost[len(cost) - 2]:
            return minCost[len(cost) - 1]
        else:
            return minCost[len(cost) - 2]
