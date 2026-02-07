class Solution:
    def cutOffTree(self, forest: List[List[int]]) -> int:
        x = len(forest[0])
        y = len(forest)
        maximum = 0
        nodes = []
        one = False
        for i in range(y):
            for j in range(x):
                if forest[i][j] == 1:
                    one = True
                if forest[i][j] != 0:
                    nodes.append((forest[i][j], i, j))
                    maximum += 1

        nodes.sort()
        for i in range(len(nodes)):
            forest[nodes[i][1]][nodes[i][2]] = i + 1
            
        adj = [[] for _ in range(maximum)]
        for i in range(y):
            for j in range(x):
                if forest[i][j] == 0:
                    continue
                if i - 1 >= 0 and forest[i - 1][j] != 0:
                    adj[forest[i][j] - 1].append(forest[i - 1][j] - 1)
                if i + 1 < y and forest[i + 1][j] != 0:
                    adj[forest[i][j] - 1].append(forest[i + 1][j] - 1)
                if j - 1 >= 0 and forest[i][j - 1] != 0:
                    adj[forest[i][j] - 1].append(forest[i][j - 1] - 1)
                if j + 1 < x and forest[i][j + 1] != 0:
                    adj[forest[i][j] - 1].append(forest[i][j + 1] - 1)
        
        def dijkstra(adj, src):
            V = len(adj)
            pq = []
            dist = [sys.maxsize] * V
            dist[src] = 0
            heapq.heappush(pq, (0, src))
            while pq:
                d, u = heapq.heappop(pq)
                if d > dist[u]:
                    continue
                for v in adj[u]:
                    if dist[u] + 1 < dist[v]:
                        dist[v] = dist[u] + 1
                        heapq.heappush(pq, (dist[v], v))
            return dist
        
        totalDistance = 0
        lastNode = forest[0][0] - 1
        if lastNode < 0:
            return -1
        for i in range(1 if one else 0, maximum):
            distances = dijkstra(adj, lastNode)
            if distances[i] < sys.maxsize:
                totalDistance += distances[i]
            else:
                return -1
            lastNode = i
        return totalDistance
