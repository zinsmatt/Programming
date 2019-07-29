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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;
        auto* a = head;
        auto* b = head->next;
        while (b)
        {
            while (b && b->val == a->val)
                b = b->next;
            if (b)
            {
                a->next = b;
                a = b;
                b = b->next;
            }
        }
        a->next = nullptr;
        return head;
    }
};