import numpy as np
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        copy = np.array(board)

        m = len(copy)
        n = len(copy[0])

        sums = np.empty((m, n))

        for i in range(m):
            for j in range(n):
                total = np.sum(copy[(i - 1 if i - 1 >= 0 else i) : i + 2, (j - 1 if j - 1 >= 0 else j) : j + 2])
                if board[i][j] == 1 and (total < 3 or total > 4):
                    board[i][j] = 0
                elif board[i][j] == 0 and total == 3:
                    board[i][j] = 1
