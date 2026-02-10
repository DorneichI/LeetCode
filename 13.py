class Solution:
    def romanToInt(self, s: str) -> int:
        num = 0
        def oneNumeral(c):
            if c == "I":
                return 1
            elif c == "V":
                return 5
            elif c == "X":
                return 10
            elif c == "L":
                return 50
            elif c == "C":
                return 100
            elif c == "D":
                return 500
            elif c == "M":
                return 1000
            else:
                print("error")
                return 0
        
        for c in reversed(s):
            if oneNumeral(c) * 4 < num:
                num -= oneNumeral(c)
            else:
                num += oneNumeral(c)
        return num
