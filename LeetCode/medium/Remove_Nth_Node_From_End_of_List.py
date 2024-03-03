# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        r = head

        l = r
        prev_l = None
        for i in range(n):
            r = r.next

        while r is not None:
            prev_l = l
            r = r.next
            l = l.next
        if prev_l is not None:
            prev_l.next = l.next
            return head
        else:
            return l.next

