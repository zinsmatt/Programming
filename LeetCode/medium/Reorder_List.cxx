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
    void reorderList(ListNode* head) {
        
        vector<ListNode*> arr;
        auto* pt = head;
        while (pt) {
            arr.push_back(pt);
            pt = pt->next;
        }
        int l = 0, r = arr.size()-1;
        for (int i = 0; i < arr.size(); ++i) {
            if (i % 2 == 0) {
                if (l == r) {
                    arr[l]->next = nullptr;
                } else {
                    arr[l]->next = arr[r];
                }
                ++l;
            } else {
                if (l == r) {
                    arr[r]->next = nullptr;
                } else {
                    arr[r]->next = arr[l];
                }
                --r;
            }
        }
    }
};
