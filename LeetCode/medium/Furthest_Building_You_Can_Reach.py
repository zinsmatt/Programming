from heapq import heappush, heappop

class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        res = 0
        i = 1
        heap = []
        other = 0
        while i < len(heights):
            d = heights[i] - heights[i-1]
            if d <= 0:
                i += 1
            elif len(heap) < ladders:
                heappush(heap, d)
                i += 1
            else:
                if len(heap) > 00 and d > heap[0]:
                    v = heappop(heap)
                    heappush(heap, d)
                    other += v
                else:
                    other += d
                if other > bricks:
                    break
                else:
                    i += 1
        return i-1
