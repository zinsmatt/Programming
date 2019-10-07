/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        if (!root)
            return vector<int>();
        vector<int> res = {root->val};
        for (auto* c : root->children)
        {
            auto p = preorder(c);
            res.insert(res.end(), p.begin(), p.end());            
        }
        return res;
    }
    
};