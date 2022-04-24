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
    int pairSum(ListNode* head) {
        int res = 0;
        std::stack<int> s;
        auto* h = head;
        int n = 0;
        while (h) {
            ++n;
            h = h->next;
        }
        auto *pt = head;
        for (int i = 0; i < n/2; ++i) {
            s.push(pt->val);
            pt = pt->next;
        }
        while (!s.empty()) {
            auto a = s.top();
            s.pop();
            res = std::max(a + pt->val, res);
            pt = pt->next;
        }
        return res;        
    }
};
