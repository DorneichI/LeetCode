class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hsh = {}
        for string in strs:
            key = "".join(sorted(string))
            if key in hsh:
                hsh[key].append(string)
            else:
                hsh[key] = [string]
        
        output = []
        for key in hsh:
            output.append(hsh[key])
        
        return output
