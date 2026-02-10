class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        diagonalsY = []
        for i in range(len(mat)):
            y = i
            x = 0
            diagonal = []
            while y < len(mat) and x < len(mat[0]):
                diagonal.append(mat[y][x])
                y += 1
                x += 1
            diagonalsY.append(diagonal)
        
        diagonalsX = []
        for i in range(len(mat[0])):
            y = 0
            x = i
            diagonal = []
            while y < len(mat) and x < len(mat[0]):
                diagonal.append(mat[y][x])
                y += 1
                x += 1
            diagonalsX.append(diagonal)
        
        for i in range(len(diagonalsY)):
            diagonalsY[i].sort()
        for i in range(len(diagonalsX)):
            diagonalsX[i].sort()

        for i in range(len(mat)):
            y = i
            x = 0
            while y < len(mat) and x < len(mat[0]):
                mat[y][x] = diagonalsY[i][x]
                y += 1
                x += 1
        for i in range(len(mat[0])):
            y = 0
            x = i
            while y < len(mat) and x < len(mat[0]):
                mat[y][x] = diagonalsX[i][y]
                y += 1
                x += 1
                
        return mat
