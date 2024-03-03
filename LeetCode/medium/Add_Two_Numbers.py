# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        retenue = 0
        a = l1
        b = l2
        res = ListNode(-1)
        cur = res
        while a is not None or b is not None:
            s = retenue
            if a is not None:
                s += a.val
                a = a.next
            if b is not None:
                s += b.val
                b = b.next
            cur.next = ListNode(s % 10)
            cur = cur.next
            retenue = s // 10
        while retenue > 0:
            cur.next = ListNode(retenue % 10)
            retenue = retenue // 10
        return res.next
            
