
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
    ListNode* reverseList(ListNode* head) {
	if (!head) return head;
	auto *b = head;
	auto *c = b;
c = c->next;
	if (!c) return head;
	ListNode* a = nullptr;
while (b) {
	b->next = a;
	a = b;
	b = c;
	if (c ) c = c->next;
}
return a;
    }
};

