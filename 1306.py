class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        queue = deque([start])
        l = len(arr)
        while len(queue) > 0:
            i = queue.popleft()
            if i - arr[i] >= 0:
                if arr[i - arr[i]] > 0:
                    queue.append(i - arr[i])
                elif arr[i - arr[i]] == 0:
                    return True
            if i + arr[i] < l:
                if arr[i + arr[i]] > 0:
                    queue.append(i + arr[i])
                elif arr[i + arr[i]] == 0:
                    return True
            arr[i] = -1
        return False
