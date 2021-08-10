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
        std::cout << "List: ";
        while (p)
        {
            std::cout << p->val << " ";
            p = p->next;
        }
        std::cout << "\n";
    }
    
    pair<ListNode*, ListNode*> reverse(ListNode* head, int n)
    {
        //display(head);
        //cout << n << "\n";
        if (n == 1)
        {
            return {head, head};
        }
        else if (n == 2)
        {
            ListNode* b = head->next;
            b->next = head;
            return {b, head};
        }
        else
        {
            ListNode* initial_head = head;
            ListNode* a = head;
            ListNode* b = a->next;
            ListNode* c = b->next;
            for (int i = 0; i < n-1; ++i)
            {
                b->next = a;
                a = b;
                b = c;
                if (c)
                    c = c->next;
            }
            return {a, initial_head};
        }
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* nouv = new ListNode();
        nouv->next = head;
        
        // find start
        ListNode *pt = nouv;
        ListNode *prev = nouv;
        for (int i = 0; i < left; ++i)
        {
            prev = pt;
            pt = pt->next;
        }
        
        // find next after
        ListNode *after = pt->next;
        for (int i = 0; i < right-left; ++i)
        {
            after = after->next;
        }
        
        // reverse
        auto  [l, r] = reverse(pt, right-left+1);
        prev->next = l;
        r->next = after;

        return nouv->next;
    }
};
