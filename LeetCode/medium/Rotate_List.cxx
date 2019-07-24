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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0)
            return head;
        int n = 0;
        auto * p = head;
        while (p)
        {
            ++n;
            p = p->next;
        }
        
        if (n <= 1)
            return head;
        auto *b = head;
        for (int i = 0; i < n - (k % n); ++i)
        {
            b = b->next;
        }
        if (b == head || !b)
            return head;
        auto *t = b;
        while (t->next)
            t = t ->next;
        t->next = head;
        while (t->next != b)
            t = t->next;
        t->next = NULL;
        return b;
    }
};