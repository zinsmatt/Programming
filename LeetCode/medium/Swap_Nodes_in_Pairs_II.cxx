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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode *temp = new ListNode;
        auto* prev = temp;

        ListNode *a = head;
        ListNode *b = head->next;

        while (a && b)
        {
            a->next = b->next;
            prev->next = b;
            b->next = a;

            prev = a;
            a = a->next;
            if (a)
                b = a->next;
        }

        auto *new_head = temp->next;
        delete temp;
        return new_head;
    }
};
