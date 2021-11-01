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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

pair<ListNode*, ListNode*> split(ListNode* l)
{
    if (!l)
    {
        return make_pair(nullptr, nullptr);
    }

    ListNode *a = l, *b = l;
    ListNode* prev=nullptr;
    while (b)
    {
        b = b->next;
        if (b)
        {
            b = b->next;
        }
        else
        {
            break;
        }
        prev = a;
        a = a->next;
    }
    
    if (prev)
    {
        prev->next = nullptr;
    }
    else
    {
        l = prev;
    }
    return make_pair(l, a);
}


class Solution {
    
    TreeNode* solve(ListNode* n)
    {
        if (n)
        {
            auto p = split(n);
            auto *l = p.first;
            auto *r = p.second;
            /*std::cout << "split: ";
            if (!l) cout << "null ";
            else cout << l->val << " ";
            if (!r) cout << "null ";
            else cout << r->val << " ";*/
            
            TreeNode* nouv = new TreeNode(r->val);
            nouv->left = solve(l);
            nouv->right = solve(r->next);
            return nouv;
        }
        else
        {
            return nullptr;
        }
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        return solve(head);
    }
};
