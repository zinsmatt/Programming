# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        cur = node
        n = node.next
        prev = None
        while n is not None:
            prev = cur
            cur.val = n.val
            cur = n
            n = n.next
        prev.next = None
