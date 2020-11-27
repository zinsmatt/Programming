# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def solve(n, m):
    if not n:
        return 0
    return (m <= n.val) + solve(n.left, max(n.val, m)) + solve(n.right, max(n.val, m))
    
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        return solve(root, -99999)
