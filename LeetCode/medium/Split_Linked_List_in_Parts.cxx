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
    void display(ListNode* p)
    {
        while (p)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << "\n";
    }
    
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        auto *p = head;
        int n = 0;
        while (p)
        {
            ++n;
            p = p->next;
        }
        
        int r = n % k;
        int s = n / k;

        
        vector<ListNode*> res(k, nullptr);
        auto* cur = head;
        int i = 0;
        int index = 0;
        while (i < n)
        {
            int t = s + (index < r);
            if (t == 0) break;
            
            
            res[index] = cur;
            ListNode* prev = nullptr;
            for (int j = 0; j < t; ++j)
            {
                i++;
                prev = cur;
                cur = cur->next;
            }
            if (prev)
                prev->next = nullptr;
            ++index;
            
        }
//         for (auto* p : res)
//         {
//             display(p);
//         }
        
        return res;     
    }
};
