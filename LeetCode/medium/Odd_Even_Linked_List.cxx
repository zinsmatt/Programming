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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
        auto *odd = head->next;
        auto *odd_head = odd;
        auto *pt = head;
        int c = 2;
        auto* cur = odd->next;
        while (cur)
        {
            if (c % 2 == 0)
            {
                pt->next = cur;
                pt = pt->next;
            }
            else
            {
                odd->next = cur;
                odd = odd->next;
            }
            cur = cur->next;
            c++;
        }
        
        pt->next = odd_head;
        odd->next = nullptr;
        return head;        
    }
};