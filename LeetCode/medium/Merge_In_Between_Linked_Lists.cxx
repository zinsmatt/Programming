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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int i = 0;
        auto* pt = list1;
        while (i <= b) { pt = pt->next; ++i; }
        auto* end = list2;
        while (end->next) end = end->next;
        end->next = pt;
        
        
        
        
        if (a == 0) {
            list1 = list2;
        } else {
            i = 0;
            auto* pt = list1;
            while (i < a-1) { pt = pt->next; i++; }
            pt->next = list2;
        }
        return list1;
        
    }
};
