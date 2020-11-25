# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class FindElements:

    def __init__(self, root: TreeNode):
        self.values = {}
        q = [root]
        v = [0]
        while len(q):
            s = q[0]
            q = q[1:]
            x = v[0]
            v = v[1:]
            self.values[x] = 1
            if s.left:
                q += [s.left]
                v += [2*x+1]
            if s.right:
                q += [s.right]
                v += [2*x+2]

            

    def find(self, target: int) -> bool:
        return target in self.values.keys()
        


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)
