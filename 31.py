class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        def rev(start, end):
            for i in range(0, (end - start) // 2):
                tmp = nums[start + i]
                nums[start + i] = nums[end - i - 1]
                nums[end - i - 1] = tmp


        l = len(nums)
        rising = True
        n = 0
        for i in reversed(range(l)):
            if nums[i] >= n:
                n = nums[i]
            else:
                rising = False
                if nums[l - 1] > nums[i]:
                    tmp = nums[i]
                    nums[i] = nums[l - 1]
                    nums[l - 1] = nums[i + 1]
                    nums[i + 1] = tmp
                    rev(i + 2, l - 1)
                else:
                    for j in reversed(range(l)):
                        if nums[j] > nums[i]:
                            tmp = nums[j]
                            nums[j] = nums[i]
                            nums[i] = tmp
                            break
                    rev(i + 1, l)
                break

        if rising == True:
            rev(0, l)
