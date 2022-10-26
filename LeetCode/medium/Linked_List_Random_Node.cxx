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
    ListNode* h;
    int size;
    Solution(ListNode* head) {
        h = head;
        int i = 0;
        auto *pt = head;
        while (pt)
        {
            ++i;
            pt=pt->next;
        }
        size = i;
    }
    
    int getRandom() {
        const int range_from  = 0;
        const int range_to    = size-1;
        std::random_device                  rand_dev;
        std::mt19937                        generator(rand_dev());
        std::uniform_int_distribution<int>  distr(range_from, range_to);
        auto* pt = h;
        int x =  distr(generator);
        for (int i=0; i < x && pt; ++i)
            pt = pt->next;
        return pt->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
