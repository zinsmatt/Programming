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
    ListNode* removeElements(ListNode* head, int val) {
     if (head)
     {
         while (head && head->val == val)
             head = head->next;
         
         if (head)
         {
             auto * cur = head;
             auto *temp = cur->next;
             while (temp)
             {
                 if (temp->val != val)
                 {
                     cur->next = temp;
                     cur = temp;
                 }
                 temp = temp->next;
             }
             cur->next = nullptr;
         }
     }
     return head;         
    }
};