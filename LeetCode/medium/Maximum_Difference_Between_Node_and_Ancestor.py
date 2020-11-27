# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def solve(n, a, aa):
    if not n:
        return 0
    cur = max(abs(a-n.val), abs(aa-n.val))
    new_a = max(a, n.val)
    new_aa = min(aa, n.val)
    return max(cur, solve(n.left, new_a, new_aa), solve(n.right, new_a, new_aa))
    
    
class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        return solve(root, root.val, root.val)
