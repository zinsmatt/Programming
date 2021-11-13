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
    
    pair<ListNode*, ListNode*> solve(ListNode* n)
    {
        if (!n)
        {
            return {nullptr, nullptr};
        }
        auto [end, beg] = solve(n->next);
        n->next = nullptr;
        if (!end)
        {
            return {n, n};
        }
        else
        {
            end->next = n;
            return {n, beg};
        }
    }

public:
    ListNode* reverseList(ListNode* head) {
        return solve(head).second;
    }
};
