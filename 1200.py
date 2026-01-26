class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        minimum = arr[1] - arr[0]
        output = []
        for i in range(1, len(arr)):
            if arr[i] - arr[i - 1] < minimum:
                minimum = arr[i] - arr[i - 1]
                output = []
            if arr[i] - arr[i - 1] == minimum:
                output.append([arr[i - 1], arr[i]])
        return output
