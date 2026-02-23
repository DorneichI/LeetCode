class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        dct = {}
        for c in chars:
            if c in dct:
                dct[c] += 1
            else:
                dct[c] = 1
        
        total = 0
        
        for w in words:
            cpy = dct.copy()
            fits = True
            for c in w:
                if c in cpy and cpy[c] > 0:
                    cpy[c] -= 1
                else:
                    fits = False
                    break
            if fits:
                total += len(w)
        
        return total
