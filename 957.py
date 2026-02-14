class Solution:
    def prisonAfterNDays(self, cells: List[int], n: int) -> List[int]:
        nextCells = [0, 0, 0, 0, 0, 0, 0, 0]
        n = n % 14
        if n == 0:
            n += 14
        
        while n > 0:
            for i in range(1, 7):
                if cells[i - 1] == cells[i + 1]:
                    nextCells[i] = 1
                else:
                    nextCells[i] = 0
            cells = nextCells
            nextCells = [0, 0, 0, 0, 0, 0, 0, 0]
            n -= 1
            
        return cells
