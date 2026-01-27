class Solution(object):
    def minCost(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """

        adj = [[] for _ in range(n)]

        for i in range(len(edges)):
            adj[edges[i][0]].append([edges[i][1], edges[i][2]])
            adj[edges[i][1]].append([edges[i][0], edges[i][2] * 2])
        
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
                for v, w in adj[u]:
                    if dist[u] + w < dist[v]:
                        dist[v] = dist[u] + w
                        heapq.heappush(pq, (dist[v], v))
            return dist

        distances = dijkstra(adj, 0)
        return distances[n - 1] if distances[n - 1] != sys.maxsize else -1
