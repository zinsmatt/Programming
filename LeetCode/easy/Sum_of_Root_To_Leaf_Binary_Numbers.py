# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def solve(self, n, s):
        if not n:
            return 0
        
        nouv = 2 * s + n.val
        
        l = self.solve(n.left, nouv)
        r = self.solve(n.right, nouv)
        
        if r+l == 0:
            return nouv
        else:
            return l + r
        
    def sumRootToLeaf(self, root: TreeNode) -> int:
        return self.solve(root, 0)
