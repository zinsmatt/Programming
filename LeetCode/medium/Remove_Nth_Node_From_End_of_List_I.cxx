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
    pair<int, ListNode*> solve(ListNode* n, int target)
    {
        
        if (!n)
            return make_pair(1, nullptr);
                
        auto [count, ptr] = solve(n->next, target);
        if (count == target)
        {
            return make_pair(count+1, ptr);
        }
        else
        {
            n->next = ptr;
            return make_pair(count+1, n);
        }
    }
    
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return solve(head, n).second;
        
    }
};
