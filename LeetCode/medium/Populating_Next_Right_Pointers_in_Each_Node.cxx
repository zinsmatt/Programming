/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        check(root, std::vector<Node*>(),  0);
        return root;
    }
    
    vector<Node*> check(Node* n, vector<Node*> rights,  int l)
    {
        if (n)
        {
            if (rights.size() == l)
            {
                rights.push_back(nullptr);
            }
            
            rights = check(n->right, rights, l+1);
            rights = check(n->left, rights,  l+1);
            
            n->next = rights[l];
            rights[l] = n;
        }
        return rights;
    }
    //vector<Node*> rights;
};