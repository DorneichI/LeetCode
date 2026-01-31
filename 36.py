class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        def in_row(i, j):
            for x in range(9):
                if board[i][x] == board[i][j] and x != j:
                    return True
            return False

        def in_cols(i, j):
            for x in range(9):
                if board[x][j] == board[i][j] and x != i:
                    return True
            return False

        def in_box(x, y, i, j):
            for m in range(x, x + 3):
                for n in range(y, y + 3):
                    if board[m][n] == board[i][j] and m != i and n != j:
                        return True
            return False

        for i in range(len(board)):
            for j in range(len(board)):
                if board[i][j] != "." and in_cols(i, j):
                    return False
                if board[i][j] != "." and in_row(i, j):
                    return False
                if board[i][j] != "." and in_box(i // 3 * 3, j // 3 * 3, i, j):
                    return False
        return True
        
        # rows = [set() for _ in range(9)]
        # cols = [set() for _ in range(9)]
        # boxes = [set() for _ in range(9)]

        # for i in range(len(board)):
        #     for j in range(len(board)):
        #         if board[i][j] != "." and board[i][j] in cols[i]:
        #             return False
        #         else:
        #             cols[i].add(board[i][j])
        #         if board[i][j] != "." and board[i][j] in rows[j]:
        #             return False
        #         else:
        #             rows[j].add(board[i][j])
        #         if board[i][j] != "." and board[i][j] in boxes[i // 3 * 3 + j // 3]:
        #             return False
        #         else:
        #             boxes[i // 3 * 3 + j // 3].add(board[i][j])
        # return True
