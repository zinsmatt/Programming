/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    
    void solve(Node* n, int l, vector<Node*>& v)
    {
        if (!n) return;
        if (v[l])
        {
            v[l]->next = n;
        }
        v[l] = n;
        solve(n->left, l+1, v);
        solve(n->right, l+1, v);
    }
    
public:
    Node* connect(Node* root) {
        vector<Node*> levels(1000, nullptr);
        solve(root, 0, levels);
        for (auto p : levels)
        {
            if (p)
                p->next = nullptr;
        }
        return root;
    }
};
