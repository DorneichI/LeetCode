class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        output = []
        for c in words[0]:
            cInAll = True
            for i in range(1,len(words)):
                found = words[i].find(c)
                if found < 0:
                    cInAll = False
                    break
                else:
                    words[i] = words[i][:found] + words[i][found + 1:]
            if cInAll:
                output.append(c)
        return output
