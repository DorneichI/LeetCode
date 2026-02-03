class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        rows = [[] for _ in range(numRows)]
        column = 0
        row = 0
        for c in s:
            if column % (numRows - 1)== 0:
                rows[row].append(c)
                row += 1
                if row == numRows:
                    row -= 2
                    column += 1
            else:
                rows[row].append(c)
                row -= 1
                column += 1
        for i in range(numRows):
            rows[i] = ''.join(rows[i])
        return ''.join(rows)
