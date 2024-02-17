class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        def ind(c):
            return ord(c)-ord('a')

        last = [-1] * 26
        for i, c in enumerate(s):
            last[ind(c)] = i
        
        ok = [False] * 26

        st = []

        for i, c in enumerate(s):
            if ok[ind(c)]:
                continue
            if len(st) == 0:
                st.append(c)
                ok[ind(c)] = True
            else:
                while len(st) > 0 and st[-1] > c and last[ind(st[-1])] > i:
                    v = st.pop(-1)
                    ok[ind(v)] = False
                st.append(c)
                ok[ind(c)] = True
        return "".join(map(str, st))

