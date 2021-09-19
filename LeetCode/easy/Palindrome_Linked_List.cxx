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
    bool isPalindrome(ListNode* head) {
        
        auto* p = head;
        int c = 0;
        while (p)
        {
            c++;
            p = p->next;
        }
        p = head;
        stack<int> s;
        for (int i = 0; i < c/2; ++i)
        {
            s.push(p->val);
            p = p->next;
        }
        if (c % 2 == 1)
            p = p->next;
        while (p)
        {
            if (s.top() == p->val)
            {
                s.pop();
            }
            else
            {
                return false;
            }
            p = p->next;
        }
        return true;
    }
};
