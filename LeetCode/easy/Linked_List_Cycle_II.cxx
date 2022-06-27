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
    bool hasCycle(ListNode *head) {
        if (!head)
            return false;

        auto *f = head;
        auto *s = head;
        bool slow = false;
        while (f && s) {
            f = f->next;
            if (slow) s = s->next;
            slow = !slow;
            
            if (f == s)
                return true;
        }
        return false;
    }
};
