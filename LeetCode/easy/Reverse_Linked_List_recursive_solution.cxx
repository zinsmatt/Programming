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
        if (!head)
            return nullptr;
        auto res = rev(head);
        return res.first;
    }
    
    pair<ListNode*, ListNode*> rev(ListNode* n)
    {
        if (n->next)
        {
            auto res = rev(n->next);
            auto* new_prev = res.second;
            new_prev->next = n;
            n->next = nullptr;
            return std::make_pair(res.first, n);
        }
        else
        {
            return std::make_pair(n, n);
        }
    }
};