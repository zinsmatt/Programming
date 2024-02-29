class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        indeg = [0] * n
        for l in leftChild:
            if l >= 0:
                indeg[l] += 1
        for r in rightChild:
            if r >= 0:
                indeg[r] += 1
        root = -1
        for i, x in enumerate(indeg):
            if x == 0:
                if root != -1:
                    return False
                else:
                    root = i
        ok = [0] * n
        def validate(n):
            if n >= 0 and ok[n] < 2:
                ok[n] += 1
                validate(leftChild[n])
                validate(rightChild[n])
        validate(root)
        return all(x == 1 for x in ok)
