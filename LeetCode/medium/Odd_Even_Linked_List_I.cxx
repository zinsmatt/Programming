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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode;
        auto* odd_head = odd;
        ListNode* even = new ListNode;
        auto* even_head = even;
        int i = 1;
        while (head)
        {
            auto *p = head;
            head = head->next;
            p->next = nullptr;
            if (i % 2)
            {
                odd->next = p;
                odd = odd->next;
            }
            else
            {
                even->next = p;
                even = even->next;
            }
            ++i;
        }
        odd->next = even_head->next;
        return odd_head->next;
        
    }
};
