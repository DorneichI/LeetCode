class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])
        def onesRow(x):
            return sum(grid[x])
        
        def onesCol(x):
            total = 0
            for i in range(m):
                total += grid[i][x]
            return total

        onesR = []
        zerosR = []
        for i in range(m):
            onesR.append(onesRow(i))
            zerosR.append(n - onesR[i])
        
        onesC = []
        zerosC = []
        for i in range(n):
            onesC.append(onesCol(i))
            zerosC.append(m - onesC[i])
        

        output = [[0] * len(grid[0]) for _ in range(len(grid))]
        for i in range(len(output)):
            for j in range(len(output[i])):
                output[i][j] = onesR[i] + onesC[j] - zerosR[i] - zerosC[j]
        return output
