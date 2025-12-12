class Solution:
    def countMentions(self, numberOfUsers: int, events: List[List[str]]) -> List[int]:
        count = [0] * numberOfUsers
        offline = [0] * numberOfUsers
        events = sorted(events, key=lambda x: x[0], reverse=True)
        events = sorted(events, key=lambda x: (int(x[1])))
        for event in events:
            if event[0] == "OFFLINE":
                offline[int(event[2])] = int(event[1]) + 60
            # event[0] = "MESSAGE"
            elif event[2] == "HERE":
                for i in range(numberOfUsers):
                    if (offline[i] <= int(event[1])):
                        count[i] += 1
            elif event[2] == "ALL":
                count = [x + 1 for x in count]
            # event[2] = "idx ..."
            else:
                for id in event[2].split(" "):
                    count[int(id[2:])] += 1
        return count