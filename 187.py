class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        sequences = {}
        for i in range(len(s) - 9):
            if s[i:i+10] in sequences:
                sequences[s[i:i+10]] = True
            else:
                sequences[s[i:i+10]] = False
        output = []
        for key in sequences:
            if sequences[key]:
                output.append(key)
        return output
