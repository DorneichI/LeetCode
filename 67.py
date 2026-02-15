class Solution:
    def addBinary(self, a: str, b: str) -> str:
        iA = len(a) - 1
        iB = len(b) - 1
        carry = 0

        result = ""

        while iA >= 0 and iB >= 0:
            if carry == 1:
                result = "1" + result if a[iA] == b[iB] else "0" + result
                carry = 0 if a[iA] == "0" and b[iB] == "0" else 1
            else:
                result = "1" + result if a[iA] != b[iB] else "0" + result
                carry = 0 if a[iA] == "0" or b[iB] == "0" else 1
            iA -= 1
            iB -= 1

        while iA >= 0:
            if carry == 1:
                result = "1" + result if a[iA] == "0" else "0" + result
                carry = 1 if a[iA] == "1" else 0
            else:
                result = "1" + result if a[iA] == "1" else "0" + result
            iA -= 1
        
        while iB >= 0:
            if carry == 1:
                result = "1" + result if b[iB] == "0" else "0" + result
                carry = 1 if b[iB] == "1" else 0
            else:
                result = "1" + result if b[iB] == "1" else "0" + result
            iB -= 1

        if carry == 1:
            result = "1" + result
        
        return result
