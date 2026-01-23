class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        def getMorph(string):
            table = {}
            morph = []
            uniqueChars = 0
            for c in string:
                if c in table:
                    morph.append(table[c])
                else:
                    table[c] = uniqueChars
                    morph.append(uniqueChars)
                    uniqueChars += 1
            return morph, uniqueChars

        morph1, c1 = getMorph(s)
        morph2, c2 = getMorph(t)

        if c1 != c2 or len(morph1) != len(morph2):
            return False
        for i in range(len(morph1)):
            if morph1[i] != morph2[i]:
                return False
        return True
