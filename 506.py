class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        ranks = [(i, score[i]) for i in range(len(score))]

        def mySorting(e):
            return e[1]

        ranks.sort(key=mySorting, reverse=True)

        ranks = [(ranks[i][0], i + 1) for i in range(len(ranks))]

        def mySorting2(e):
            return e[0]

        ranks.sort(key=mySorting2)

        def medalAssigner(i):
            if i == 1:
                return "Gold Medal"
            elif i == 2:
                return "Silver Medal"
            elif i == 3:
                return "Bronze Medal"
            else:
                return str(i)

        ranks = [medalAssigner(ranks[i][1]) for i in range(len(ranks))]

        return ranks
