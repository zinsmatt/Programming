# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def is_pseudo_pal(x):
    return sum([x.count(i)%2 for i in range(10)]) <= 1
    
def solve(n, l):
    if not n:
        return 0
    
    new_l = l + [n.val]
    if not n.right and not n.left:
        return int(is_pseudo_pal(new_l))

    return solve(n.left, new_l) + solve(n.right, new_l)
    
        
class Solution:
    def pseudoPalindromicPaths (self, root: TreeNode) -> int:
        return solve(root, [])
        
