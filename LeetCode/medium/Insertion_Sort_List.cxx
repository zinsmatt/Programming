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
    ListNode* insertionSortList(ListNode* head) {
        if (!head)
            return head;
        ListNode* head_sorted = head;
        head = head->next;
        head_sorted->next = nullptr;
        while (head)
        {
            auto* tmp = head;
            head = head->next;
            insert(head_sorted, tmp);
        }
        return head_sorted;
    }
    
    void insert(ListNode*& head, ListNode* n)
    {
        if (n)
        {
            if (n->val < head->val)
            {
                n->next = head;
                head = n;
            }
            else
            {
                ListNode* cur = head;
                while (cur->next && cur->next->val < n->val)
                {
                    cur = cur->next;
                }
                n->next = cur->next;
                cur->next = n;
            }
        }
    }
};