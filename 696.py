class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        total = 0
        zFirst = 0
        oFirst = 0
        zeroes = True
        for c in s:
            if c == "0":
                if not zeroes:
                    zFirst = 0
                    zeroes = True
                zFirst += 1
                oFirst -= 1
            else:
                if zeroes:
                    oFirst = 0
                    zeroes = False
                zFirst -= 1
                oFirst += 1
            if zeroes and oFirst >= 0:
                total += 1
            elif not zeroes and zFirst >= 0:
                total += 1

        return total
