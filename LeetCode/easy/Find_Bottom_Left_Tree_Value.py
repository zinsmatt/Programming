# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        def find(root, level):
            if root is not None:
                dl, vl = find(root.left, level + 1)
                dr, vr = find(root.right, level + 1)
                d = level
                v = root.val
                if dl > d:
                    d = dl
                    v = vl
                if dr > d:
                    d = dr
                    v = vr
                return d, v
            else:
                return -1, -1
        d, v = find(root, 0)
        return v
