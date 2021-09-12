/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* nouv_head = new Node(0);
        Node* p = head;
        Node* prev = nouv_head;
        unordered_map<Node*, Node*> m;
        while (p)
        {
            Node* n = new Node(p->val);
            prev->next = n;
            n->random = p->random;
            m[p] = n;            
            prev = n;
            p = p->next;
        }
        p = nouv_head->next;
        while (p)
        {
            p->random = m[p->random];
            p = p->next;
        }
        auto* res = nouv_head->next;
        delete nouv_head;
        return res;
    }
};
