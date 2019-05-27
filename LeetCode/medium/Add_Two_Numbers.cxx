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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int r = 0;
        ListNode *nouv = NULL;
        ListNode *res = nouv;
        while (l1 || l2 || r > 0) {
            int value = r;
            if (l1)
            {
                value += (l1)->val;
                l1 = l1->next;                
            }
            if (l2)
            {
                value += (l2)->val;
                l2 = l2->next;                
            }
            if (!nouv)
            {
                nouv = new ListNode(0);
                res = nouv;
            } else
            {
                nouv->next = new ListNode(0);
                nouv = nouv->next;
            }
            
            nouv->val = value % 10;
            r = value / 10;
        }
        return res;
    }
};