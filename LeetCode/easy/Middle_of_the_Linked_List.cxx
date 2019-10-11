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
    ListNode* middleNode(ListNode* head) {
        auto *fast = head;
        auto *slow = head;
        bool move = false;
        while (fast)
        {
            fast = fast->next;
            if (move)
                slow = slow->next;
            move = !move;            
        }
        return slow;
    }
};