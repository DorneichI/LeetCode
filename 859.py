class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        different = []
        unique = {}
        for i in range(len(s)):
            if s[i] != goal[i]:
                different.append(i)
            else:
                unique[s[i]] = True
        if len(different) == 2:
            return goal[different[0]] ==  s[different[1]] and goal[different[1]] ==  s[different[0]]
        elif len(different) == 0 and len(unique) < len(s):
            return True
        else:
            return False
