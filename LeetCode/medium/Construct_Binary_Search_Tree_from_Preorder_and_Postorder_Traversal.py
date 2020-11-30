# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def solve(pre, post, x):
    #print("call : ", pre, post, x)
    root = TreeNode(x)
    if len(pre) == 0 or len(post) == 0:
        return root
    
    
    left = pre[0]
    idx = post.index(left)
    #print("left index = ", idx)
    root.left = solve(pre[1:idx+1], post[:idx], left)
    
    if idx < len(post)-1:
        #print("Handle right part")
        #print("idx+1 = ", idx+1)
        right = pre[idx+1]
        idx2 = post.index(right)
        n = idx2 - idx - 1
        #print("idx, n = ", idx, n)
        root.right = solve(pre[idx+2:idx+2+n], post[idx+1:idx+1+n], right)
    return root
    
    
        
class Solution:
    def constructFromPrePost(self, pre: List[int], post: List[int]) -> TreeNode:

        return solve(pre[1:], post[:-1], pre[0])
