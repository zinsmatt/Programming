
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

pair<ListNode*, ListNode*> reverse_recursive(ListNode* n) {
	if (!n) return {nullptr, nullptr};

	auto [last, head] = reverse_recursive(n->next);
    if (last)
        last->next = n;
    else
        head = n;
	n->next = nullptr;
	return {n, head};
}

public:
    ListNode* reverseList(ListNode* head) {
	if (!head) return head;
auto [last, new_head] = reverse_recursive(head);	
return new_head;
    }
};

