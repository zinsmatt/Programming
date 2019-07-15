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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2)
            return nullptr;
        ListNode *head = l1;
        if (!l1)
        {
            head = l2;
            l2 = l2->next;
        }
        else if (!l2)
        {
            head = l1;
            l1 = l1->next;
        }
        else
        {
            if (l1->val > l2->val)
            {
                head = l2;
                l2 = l2->next;
            }
            else
            {
                head = l1;
                l1 = l1->next;
            }
        }
        

        ListNode *cur = head;
        while (l1 || l2)
        {
            if (l1 && (!l2 || l2->val > l1->val))
            {
                auto* temp = l1;
                l1 = l1->next;
                cur->next = temp;
                cur = temp;
            }
            else if (l2 && (!l1 || l1->val >= l2->val))
            {
                auto* temp = l2;
                l2 = l2->next;
                cur->next = temp;
                cur = temp;
            }
        }
        return head;
        
    }
};