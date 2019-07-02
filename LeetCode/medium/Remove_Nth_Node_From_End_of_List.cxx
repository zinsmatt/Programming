/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *a = head, *b = head;
        ListNode *a_prev = nullptr;
        for (int i = 0; i < n-1; ++i)
        {
            b = b->next;
            if (!b)
                return head;
        }
        while (b->next)
        {
            a_prev = a;
            a = a->next;
            b = b->next;
        }
        
        if (a_prev == nullptr)
            return a->next;
        else
        {
            a_prev->next = a->next;
            return head;
        }
        
    }
};