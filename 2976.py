class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        adj = {}
        for i in range(len(original)):
            if original[i] in adj:
                adj[original[i]].append([changed[i], cost[i]])
            else:
                adj[original[i]] = [[changed[i], cost[i]]]
        for key in changed:
            if key not in adj:
                adj[key] = []
        for key in source:
            if key not in adj:
                adj[key] = []
        
        def dijkstra(adj, src):
            V = len(adj)
            pq = []
            dist = {}
            for key in original + changed:
                dist[key] = sys.maxsize
            dist[src] = 0
            heapq.heappush(pq, (0, src))
            while pq:
                d, u = heapq.heappop(pq)
                if d > dist[u]:
                    continue
                for v, w in adj[u]:
                    if dist[u] + w < dist[v]:
                        dist[v] = dist[u] + w
                        heapq.heappush(pq, (dist[v], v))
            return dist

        distances = {}
        totalCost = 0
        for i in range(len(source)):
            if source[i] not in distances:
                distances[source[i]] = dijkstra(adj, source[i])
            if target[i] not in distances[source[i]]:
                return -1
            cost = distances[source[i]][target[i]]
            if cost == sys.maxsize:
                return - 1
            totalCost += cost
        return totalCost
