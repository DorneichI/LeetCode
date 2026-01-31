class Solution:
    def countAndSay(self, n: int) -> str:
        def RLE(string):
            lastC = ""
            count = 0
            rle = ""
            for c in string:
                if c == lastC:
                    count += 1
                else:
                    if count > 0:
                        rle += str(count) + lastC
                    lastC = c
                    count = 1
            if count > 0:
                rle += str(count) + lastC
            return rle
        
        rle = "1"
        for i in range(n - 1):
            rle = RLE(rle)
        return rle
