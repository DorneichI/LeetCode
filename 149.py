class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        if len(points) == 1:
            return 1

        table = {}
        for i in range(len(points)):
            for j in range(i + 1, len(points)):
                if points[j][0] != points[i][0]:
                    m = (points[j][1] - points[i][1]) / (points[j][0] - points[i][0])
                else:
                    m = float('inf')

                if m == 0:
                    t = points[i][1]
                elif m == float('inf'):
                    t = points[i][0]
                elif points[i][0] != 0:
                    t = points[i][1] - (points[i][0] * m)
                else:
                    t = points[j][1] - (points[j][0] * m)

                if (m, t) in table:
                    table[(m, t)].update([(points[i][0], points[i][1]), (points[j][0], points[j][1])])
                else:
                    table[(m, t)] = set([(points[i][0], points[i][1]), (points[j][0], points[j][1])])

        maximum = 0
        for key in table:
            if len(table[key]) > maximum:
                maximum = len(table[key])

        return maximum

