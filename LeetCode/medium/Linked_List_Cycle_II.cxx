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
    ListNode *detectCycle(ListNode *head) {
        auto *p = head;
        unordered_map<ListNode*, int> m;
        while (p && m.find(p) == m.end()) {
            m[p] = 1;
            p = p->next;
        }
        return p;
    }
};
