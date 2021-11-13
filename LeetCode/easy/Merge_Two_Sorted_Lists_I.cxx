/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {



public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *n = new ListNode();
        auto* head = n;
        while (l1 || l2)
        {
            if (!l1)
            {
                n->next = l2;
                n = l2;
                l2 = l2->next;
            }
            else if (!l2)
            {
                n->next = l1;
                n = l1;
                l1 = l1->next;
            } 
            else
            {
                if (l1->val > l2->val)
                {
                    n->next = l2;
                    n = l2;
                    l2 = l2->next;
                }
                else
                {
                    n->next = l1;
                    n = l1;
                    l1 = l1->next;
                }
            }
        }
        auto *to_del = head;
        head = head->next;
        delete to_del;
        return head;
    }
};
