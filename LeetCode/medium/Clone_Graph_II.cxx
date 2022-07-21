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
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;

        vector<Node*> g(101, nullptr);
        std::queue<Node*> q;
        if (node) {
            q.push(node);
            g[node->val] = new Node(node->val);
        }
        unordered_set<Node*> done;
        while (!q.empty()) {
            auto *n = q.front();
            q.pop();
            if (done.count(n))
                continue;
            for (auto *e : n->neighbors) {
                if (!g[e->val])
                    g[e->val] = new Node(e->val);
                g[n->val]->neighbors.push_back(g[e->val]);	
                if (done.count(e) == 0)
                    q.push(e);
            }
            done.insert(n);
        }
        return g[node->val];        
    }
};

