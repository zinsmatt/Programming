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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto *a = headA;
        auto *b = headB;
        
        if (!a || !b)
            return nullptr;
        
        std::vector<ListNode*> va, vb;
        va.push_back(a);
        vb.push_back(b);
        while (a != b)
        {
            if (a->next)
            {
                a = a->next;
                va.push_back(a);
            }
                
            if (b->next)
            {
                b = b->next;
                vb.push_back(b);
            }
            
            if (a == b)
                break;
            if (!a->next && !b->next)
            {
                break;
            }
        }
        if (!a || !b || a != b)
            return nullptr;
        else
        {
            //std::cout << "val =) " << a->val << " " << b->val << "\n";
            int ia = va.size()-1;
            int ib = vb.size()-1;
            //std::cout << ia << " " << ib << "\n";
            while (ia >= 0 && ib >= 0 && va[ia] == vb[ib])
            {
                --ia;
                --ib;
            }
            return va[ia+1];
        }
    }
};