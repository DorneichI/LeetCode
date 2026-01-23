class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        morph = s.split()
        if len(morph) != len(pattern):
            return False
        
        table1 = {}
        table2 = {}
        for p, m in zip(pattern, morph):
            if p not in table1:
                table1[p] = m
            else:
                if table1[p] != m:
                    return False
            if m not in table2:
                table2[m] = p
            else:
                if table2[m] != p:
                    return False

        return True

