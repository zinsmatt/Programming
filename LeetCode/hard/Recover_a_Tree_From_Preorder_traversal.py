# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def d(s):
    if len(s) == 0 or s[0] != '-':
        return 0, s
    i = 0
    while s[i] == '-':
        i+=1
    return i, s[i:]
def n(s):
    if len(s) == 0 or s[0] == '-':
        return -1, s
    i = 0
    while i < len(s) and s[i].isnumeric():
        i+=1
    return int(s[:i]), s[i:]
        
    
class Solution:
    def recoverFromPreorder(self, S: str) -> TreeNode:
        s = S
        cur_x, s = n(s)
        cur_lvl = 0
        
        t = TreeNode(cur_x)
        root = t
        st = []
        while 1:
            lvl, s = d(s)
            if lvl == 0:
                break
            x, s = n(s)
            print(lvl, x)
            
            if lvl > cur_lvl:
                t.left = TreeNode(x)
                st = [t] + st
                t = t.left
            elif lvl == cur_lvl:
                t = st[0]
                t.right = TreeNode(x)
                t = t.right
            else:
                for i in range(cur_lvl-lvl):
                    st = st[1:]
                t = st[0]
                t.right = TreeNode(x)
                t = t.right
            cur_lvl = lvl
        return root    
            
            
            
            
        
