/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        fill(root);
    }
    
    void fill(TreeNode* n)
    {
        if (n)
        {
            fill(n->left);
            values.push_back(n->val);
            fill(n->right);            
        }
    }
    
    /** @return the next smallest number */
    int next() {
        return values[idx++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return idx < values.size();
    }
    
    vector<int> values;
    int idx = 0;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */