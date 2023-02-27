/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {

    Node* solve(vector<vector<int>>& g, int i, int j, int n) {
        cout << "solve " << i << " " << j << " " << n << "\n";
        Node *node = new Node;

        if (n == 1) {
            node->val = g[i][j];
            node->isLeaf = true;
            return node;
        } else {
            int n2 = n / 2;
            node->isLeaf = false;
            node->topLeft = solve(g, i, j, n2);
            node->topRight = solve(g, i, j+n2, n2);
            node->bottomLeft = solve(g, i+n2, j, n2);
            node->bottomRight = solve(g, i+n2, j+n2, n2);
            if (node->topLeft->val == node->topRight->val &&  node->topLeft->val == node->bottomLeft->val &&  node->topLeft->val == node->bottomRight->val &&
                node->topLeft->isLeaf && node->topRight->isLeaf && node->bottomLeft->isLeaf && node->bottomRight->isLeaf) {
                    node->val = g[i][j];
                    node->isLeaf = true;
                    node->topLeft = nullptr;
                    node->topRight = nullptr;
                    node->bottomLeft = nullptr;
                    node->bottomRight = nullptr;
            }
            return node;
        }
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid, 0, 0, grid.size());
    }
};
