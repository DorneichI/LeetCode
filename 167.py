class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        low = 0
        high = len(numbers) - 1

        i = 0
        while i < high:
            actualTarget = target - numbers[i]
            
            low = i + 1
            while low <= high:
                mid = low + (high - low) // 2
                if numbers[mid] == actualTarget:
                    return [i + 1, mid + 1]
                elif numbers[mid] < actualTarget:
                    low = mid + 1
                else:
                    high = mid - 1

            i += 1
