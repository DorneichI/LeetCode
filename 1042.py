class Solution:
    def gardenNoAdj(self, n: int, paths: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(n)]
        
        for i in paths:
            adj[i[0] - 1].append(i[1] - 1)
            adj[i[1] - 1].append(i[0] - 1)
    
        colours = [-1 for _ in range(n)]
        
        def noNeighbourOfColour(garden, colour):
            for neighbour in adj[garden]:
                if colours[neighbour] == colour:
                    return False
            return True
        
        for i in range(n):
            for j in range(1, 5):
                if noNeighbourOfColour(i, j):
                    colours[i] = j
                    break
                    
        return colours
