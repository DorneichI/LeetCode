class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        def getNextWord(s):
            i = 0
            j = 0
            while i < len(s):
                while i < len(s) and not s[i].isalnum():
                    i += 1
                j = i
                while j < len(s) and s[j].isalnum():
                    j += 1
                yield i, j
                i = j
        
        ht = {}
        gen = getNextWord(paragraph)
        for word in gen:
            key = paragraph[word[0]:word[1]].lower()
            if key in banned:
                continue
            if key in ht:
                ht[key] += 1
            else:
                ht[key] = 1
        
        maximum = 0
        maximumKey = None
        for key, value in ht.items():
            if value > maximum:
                maximum = value
                maximumKey = key
        return maximumKey
