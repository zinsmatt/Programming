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
    
    ListNode* get_mid(ListNode *n)
    {
        auto *fast = n;
        auto *slow = n;
        ListNode *prev = nullptr;
        while (fast)
        {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
            if (fast)
                fast = fast->next;
        }
        if (prev)
            prev->next = nullptr;
        return slow;
    }
    
    
    ListNode* merge(ListNode* l, ListNode* r)
    {
        ListNode* nouv = new ListNode(0);
        auto* nouv_head = nouv;
        while (l || r)
        {
            if (!l)
            {
                nouv->next = r;
                nouv = r;
                r = r->next;
            }
            else if (!r)
            {
                nouv->next = l;
                nouv = l;
                l = l->next;
            }
            else
            {
                if (l->val < r->val)
                {
                    nouv->next = l;
                    nouv = l;
                    l = l->next;
                } else
                {
                    nouv->next = r;
                    nouv = r;
                    r = r->next;
                }
            }
        }
        auto *res = nouv_head->next;
        delete nouv_head;
        return res;
    }
    
    
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        auto* m = get_mid(head);
        auto* l = sortList(head);
        auto* r = sortList(m);
        
        return merge(l, r);
    }
};
