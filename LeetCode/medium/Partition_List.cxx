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
    ListNode* partition(ListNode* head, int x) {
        ListNode* a = new ListNode(0, nullptr);
        ListNode* b = new ListNode(0, nullptr);
        auto* aa = a;
        auto* bb = b;
        auto* p = head;
        while (p)
        {
            auto *next = p->next;
            if (p->val < x)
            {
                aa->next = p;
                p->next = nullptr;
                aa = p;
            }
            else
            {
                bb->next = p;
                p->next = nullptr;
                bb = p;
            }
            p = next;
        }
        
        a = a->next;
        b = b->next;
        if (!a) return b;
        aa->next = b;
        return a;
    }
};
