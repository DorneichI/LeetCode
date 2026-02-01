class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        def merge(arr, low, mid, high):
            n1 = mid - low + 1
            n2 = high - mid

            lowArray = [0] * n1
            for i in range(n1):
                lowArray[i] = arr[low + i]
            highArray = [0] * n2
            for j in range(n2):
                highArray[j] = arr[mid + 1 + j]

            i = 0
            j = 0
            k = low

            while i < n1 and j < n2:
                if lowArray[i] <= highArray[j]:
                    arr[k] = lowArray[i]
                    i += 1
                else:
                    arr[k] = highArray[j]
                    j += 1
                k += 1

            while i < n1:
                arr[k] = lowArray[i]
                i += 1
                k += 1
            

            while j < n2:
                arr[k] = highArray[j]
                j += 1
                k += 1

        def mergeSort(arr, low, high):
            if low < high:
                mid = (low + high) // 2

                mergeSort(arr, low, mid)
                mergeSort(arr, mid + 1, high)

                merge(arr, low, mid, high)

        mergeSort(nums, 0, len(nums) - 1)
