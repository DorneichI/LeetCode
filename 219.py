class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        window = {}
        for i in range(k + 1 if k + 1 < len(nums) else len(nums)):
            if nums[i] in window:
                return True
            else:
                window[nums[i]] = True
        for i in range(k + 1, len(nums)):
            window[nums[i - k - 1]] = False
            if nums[i] in window and window[nums[i]]:
                return True
            else:
                window[nums[i]] = True

        return False
            
