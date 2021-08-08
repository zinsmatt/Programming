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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* head = new ListNode();
        ListNode* cur = head;
        while (1)
        {
            ListNode* best = nullptr;
            int best_index = -1;
            int min = std::numeric_limits<int>::max();
            
            for (int i = 0; i < lists.size(); ++i)
            {
                auto *pt = lists[i];
                if (pt)
                {
                    if (pt->val < min)
                    {
                        best = pt;
                        min = pt->val;
                        best_index = i;
                    }
                }
            }
            if (best)
            {
                cur->next = best;
                cur = cur->next;
                lists[best_index] = lists[best_index]->next;
            }
            else
            {
                break;
            }
        }
        return head->next;
        
    }
};
