# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        nodes = {}
        children = set()
        for parent, child, side in descriptions:
            if parent not in nodes.keys():
                nodes[parent] = TreeNode(parent)
            if child not in nodes.keys():
                nodes[child] = TreeNode(child)
            if side:
                nodes[parent].left = nodes[child]
            else:
                nodes[parent].right = nodes[child]
            children.add(child)

        for n in nodes.keys():
            if n not in children:
                return nodes[n]

        
