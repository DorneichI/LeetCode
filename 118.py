class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        pascal = [[1]]
        for i in range(numRows - 1):
            newRow = [1] * (len(pascal[i]) + 1)
            for j in range(1, len(pascal[i])):
                newRow[j] = pascal[i][j] + pascal[i][j - 1]
            pascal.append(newRow)
        return  pascal
