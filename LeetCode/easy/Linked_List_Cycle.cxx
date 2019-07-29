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
        
        auto *fast = head, *slow = head;
        int i = 0;
        while (fast && slow)
        {
            fast = fast->next;
            if (i % 2 == 1)
                slow = slow->next;
            
            if (fast == slow)
                return true;
            ++i;
        }
        return false;
        
    }
};