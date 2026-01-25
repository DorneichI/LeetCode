class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        i = 0
        m = len(mat)
        n = len(mat[0])
        if m * n / r != c:
            return mat
        newMat = []
        for x in range(r):
            newRow = []
            for y in range(c):
                newRow.append(mat[i // n][i % n])
                i += 1
            newMat.append(newRow)
    
        return newMat
