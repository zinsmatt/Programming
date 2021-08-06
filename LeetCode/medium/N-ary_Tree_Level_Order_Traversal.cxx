/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    vector<vector<int>> order;
    
    void traverse(Node* n, int i)
    {
        if (n)
        {
            order[i].push_back(n->val);
            for (auto& c : n->children)
            {
                traverse(c, i+1);
            }
        }
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        order.resize(1001);
        traverse(root, 0);
        int max_lvl = 0;
        while (max_lvl < order.size() && order[max_lvl].size() > 0)
            max_lvl++;
        order.resize(max_lvl);
        return order;        
    }
};
