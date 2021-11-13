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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* a = head;
        if (!a)
            return a;
        ListNode* b = a->next;
        if (!b)
            return a;
        ListNode* c = b->next;
        a->next = nullptr;
        while (b)
        {
            b->next = a;
            a = b;
            b = c;
            if (c)
                c = c->next;
        }
        return a;
    }
};
