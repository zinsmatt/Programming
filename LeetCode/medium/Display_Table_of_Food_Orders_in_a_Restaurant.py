class Solution:
    def displayTable(self, orders: List[List[str]]) -> List[List[str]]:
        t = {}
        items = set()
        for a, b, c in orders:
            b = int(b)
            items.add(c)
            if b in t.keys():
                if c in t[b].keys():
                    t[b][c] += 1
                else:
                    t[b][c] = 1
            else:
                t[b] = {c:1}
        
        items = sorted(items)
        res = [["Table"]+list(items)]
        for ti in sorted(t.keys()):
            row = [str(ti)]
            for it in items:
                if it in t[ti].keys():
                    row.append(str(t[ti][it]))
                else:
                    row.append("0")
            res.append(row)
            
        return res
