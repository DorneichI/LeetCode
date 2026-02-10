class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        ht1 = {}
        for i in arr1:
            if i in ht1:
                ht1[i] += 1
            else:
                ht1[i] = 1
        ht2 = {}
        for i in arr2:
            if i in ht2:
                ht2[i] += 1
            else:
                ht2[i] = 1
                
        output1 = []
        output2 = []
        for i in arr2:
            if i in ht1:
                output1 += [i for _ in range(ht1[i])]
        for key in ht1:
            if key not in ht2:
                output2 += [key for _ in range(ht1[key])]
        output2.sort()
        return output1 + output2
