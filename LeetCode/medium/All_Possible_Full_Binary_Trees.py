# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


def copy(x):
    if not x:
        return None
    else:
        cp = TreeNode(x.val)
        cp.left = copy(x.left)
        cp.right = copy(x.right)
        return cp
        
        
        
    

def build(n, memo):
    if n % 2 == 0:
        return []
    elif n == 1:
        if memo[1] is None:
            memo[1] = [TreeNode()]
        return memo[1]
    elif n == 3:
        if memo[3] is None:
            root = TreeNode()
            root.left = TreeNode()
            root.right = TreeNode()
            memo[3] = [root]
        return memo[3]
    else:
        if memo[n] is not None:
            return memo[n]
        else:
            root = TreeNode()
            res = []
            minus_2 = build(n-2, memo)
            
            for nb_l in range(1, n-2+1, 2):
                for l in build(nb_l, memo):
                    for r in build(n-1-nb_l, memo):
                        root.left = l              
                        root.right = r
                        res.append(copy(root))

            memo[n] = res
            return memo[n]

class Solution:
    
    def allPossibleFBT(self, N: int) -> List[TreeNode]:
        
        memo = [None for i in range(N+1)]
        build(N, memo)
        return memo[N]
