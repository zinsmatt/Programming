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
    
    void debug(ListNode *l, ListNode *r)
    {
        cout << "debut: ";
        auto* p = l;
        while (p && p != r)
        {
            std::cout << p->val << " ";
            p = p->next;
        }
        cout << "\n";
    }
    
    pair<ListNode*, ListNode*> reverse(ListNode* l, ListNode* r)
    {
        if (l == r)
        {

        }
        else if (l->next  == r)
        {
            l->next = nullptr;
            r->next = l;
        }
        else
        {
            ListNode *a = l;
            ListNode *b = l;
            b = b->next;
            ListNode *c = l;
            c = c->next;
            if (c)
                c = c->next;
            while (b && a != r)
            {
                b->next = a;
                a = b;
                b = c;
                if (c)
                    c = c->next;
            }
        }
        
        return {r, l};

    }
    
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* l = head;
        ListNode* r = l;
        ListNode *last = nullptr;
        ListNode *nouv_head = nullptr;
        while (1)
        {
            for (int i = 0; r && i < k-1; ++i)
            {
                r = r->next;
            }
            
            
            if (!r) {
                break;
            }
            
            
            
            auto* next = r->next;
            auto [nouv_l, nouv_r] = reverse(l, r);
            if (last)
                last->next = nouv_l;
            else
                nouv_head = nouv_l;
            nouv_r->next = next;      
            last = nouv_r;
            l = next;
            r = next;
        }
        return  nouv_head;        
    }
};
