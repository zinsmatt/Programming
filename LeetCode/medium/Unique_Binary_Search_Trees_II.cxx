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
class Solution {
    vector<vector<int>> res;
    void insert(TreeNode* n, int x) {
        if (x < n->val) {
            if (!n->left)
            {
                n->left = new TreeNode(x);
            }
            else
                insert(n->left, x);
        } else {
            if (!n->right)
            {
                n->right = new TreeNode(x);
            }
            else
                insert(n->right, x);
        }
    }
    
    void hash(TreeNode *n, stringstream& h) {
        if (n) {
            h << n->val;
            hash(n->left, h);
            hash(n->right, h);
        } else
            h << 0;
    }
    
    TreeNode* build(const vector<int>& v, string& signature) {
        TreeNode *n = new TreeNode(v[0]);
        for (int i = 1; i < v.size(); ++i) {
            insert(n, v[i]);
        }
        
        stringstream ss;
        hash(n, ss);
        signature = ss.str();
        return n;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        vector<int> arr(n);
        std::iota(arr.begin(), arr.end(), 1);
        unordered_map<string, TreeNode*> trees;
        do {
            string s;
            auto *root = build(arr, s);
            trees[s] = root;
        } while (next_permutation(arr.begin(), arr.end())); 
        
        vector<TreeNode*> res;
        for (auto t : trees)
            res.push_back(t.second);
        return res;
    }
};
