class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]

        for i in range(len(board)):
            for j in range(len(board)):
                if board[i][j] != "." and board[i][j] in cols[i]:
                    return False
                else:
                    cols[i].add(board[i][j])
                if board[i][j] != "." and board[i][j] in rows[j]:
                    return False
                else:
                    rows[j].add(board[i][j])
                if board[i][j] != "." and board[i][j] in boxes[i // 3 * 3 + j // 3]:
                    return False
                else:
                    boxes[i // 3 * 3 + j // 3].add(board[i][j])
        return True
