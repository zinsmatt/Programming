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
    ListNode* reverseList(ListNode* head) {
        return rev(head);
    }
    
    
    ListNode* rev(ListNode* head)
    {
        if (head)
        {
            if (head->next)
            {
                auto *res = rev(head->next);
                auto tmp = head->next;
                tmp->next = head;            
                head->next = nullptr;
                return res;
            }
            else
            {
                return head;
            }
        }
        return nullptr;
    }
};