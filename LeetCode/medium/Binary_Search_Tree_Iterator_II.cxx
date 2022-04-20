/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    vector<int> v;
    int idx;
    
    void in_order_fill(TreeNode *n) {
        if (n) {
            in_order_fill(n->left);
            v.push_back(n->val);
            in_order_fill(n->right);
        }
    }
public:
    BSTIterator(TreeNode* root) {
        idx = -1;
        in_order_fill(root);
    }
    
    int next() {
        ++idx;
        return v[idx];
        
    }
    
    bool hasNext() {
        return idx+1 < v.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
