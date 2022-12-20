class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        op = [False] * len(rooms)
        op[0] = True

        q = [rooms[0]]
        while len(q):
            new_keys = q[0]
            q = q[1:]
            for k in new_keys:
                if op[k]:
                    continue
                op[k] = True
                q.append(rooms[k])
        return sum(op) == len(rooms)
