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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* l = head;
        if (!l || !l->next)
            return l;
        ListNode* r = l->next;
        ListNode* prev = new ListNode(-111);
        auto* new_head = prev;

        while (r) {
            bool sim = false;
            while (r && l->val == r->val) {
                l = r;
                r = r->next;
                sim = true;
            }

            // if (r)
            //     std::cout << "end " << l->val << " " << r->val << "sim " << sim << "\n";
            //     std:cout << "prev = " << prev->val << "\n";
            if (!sim) {
                prev->next = l;
                prev = l;
            }
            l = r;
            if (r)
                r = r->next;
        }
        prev->next = l;
        return new_head->next;        
    }
};
