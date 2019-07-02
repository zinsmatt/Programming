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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return head;
        if (head->next == nullptr)
            return head;
        else
        {
            auto *tmp = head->next->next;
            auto* new_head = head->next;
            new_head->next = head;
            head->next = tmp;
            head = new_head;
            
        }
        
        auto *a = head->next;
        auto *b = a->next;
        if (!b)
            return head;
        auto *c = b->next;
        while (a && b && c)
        {
            //std::cout << "a b c = " << a->val << " " << b->val << " " << c->val << "\n";
            b->next = c->next;
            c->next = b;
            a->next = c;
            
            a = b;
            b = a->next;
            if (b)
                c = b->next;
            else
                break;
        }
        return head;
        
    }
};