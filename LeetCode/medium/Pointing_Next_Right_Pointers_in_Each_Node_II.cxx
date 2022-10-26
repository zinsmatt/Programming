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
    void solve(Node* n, vector<Node*>& v, int l) {
        if (n) {
            n->next = v[l];
            v[l] = n;
            solve(n->right, v, l+1);
            solve(n->left, v, l+1);
        }
    }

public:
    Node* connect(Node* root) {
        vector<Node*> v(6001, nullptr);
        solve(root, v, 0);
        return root;
    }
};




