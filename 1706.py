class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        columns = {i: i for i in range(len(grid[0]))}
        for i in range(len(grid)):
            new_columns = {}
            for j in range(len(grid[i])):
                if j in columns:
                    if grid[i][j] > 0 and j + 1 < len(grid[i]) and grid[i][j+1] > 0:
                        new_columns[j + 1] = columns[j]
                    elif grid[i][j] < 0 and j - 1 >= 0 and grid[i][j-1] < 0:
                        new_columns[j - 1] = columns[j]
            columns = new_columns
        output = [-1 for _ in range(len(grid[0]))]
        for key, value in columns.items():
            output[value] = key
        return output
