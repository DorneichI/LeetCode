class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        even = True
        for i in range(len(bits) - 1):
            if even and bits[i] == 0 and i % 2 == 0:
                even = not even
            elif not even and bits[i] == 0 and i % 2 == 1:
                even = not even
        if len(bits) % 2 == 0:
            return not even
        else:
            return even
