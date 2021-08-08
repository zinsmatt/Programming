/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> existing;
    
    Node* clone(Node* n)
    {
        if (n)
        {
            if (existing.find(n) != existing.end())
            {
                return existing [n];
            }
            
            Node* nouv = new Node(n->val);
            existing[n] = nouv;
            
            for (auto* e: n->neighbors)
            {
                nouv->neighbors.push_back(clone(e));                
            }
            return existing[n];            
        }
        return nullptr;
    }
public:
    Node* cloneGraph(Node* node) {
        return clone(node);   
    }
};
