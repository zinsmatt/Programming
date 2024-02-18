# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        def find_middle(l):
            slow = l
            fast = l
            prev = None
            while fast.next is not None:
                fast = fast.next
                if fast.next is None:
                    return slow, prev
                prev = slow
                slow = slow.next
                fast = fast.next
            return slow, prev
        
        def createBST(l):
            if l is None:
                return None
            m, prev = find_middle(l)
            nouv = TreeNode(m.val)
            if prev is not None:
                prev.next = None
                nouv.left = createBST(l)
            if m.next is not None:
                nouv.right = createBST(m.next)
            return nouv
        
        return createBST(head)


