class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        columns = {}
        rows = {}
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if matrix[i][j] == 0:
                    columns[i] = True
                    rows[j] = True
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if (i in columns and columns[i]) or (j in rows and rows[j]):
                    matrix[i][j] = 0
