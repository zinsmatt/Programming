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
    bool f(TreeNode* n, vector<int>& s, int p)
    {
        /*cout << "test " << n->val <<"\n";
        for (auto x : s) cout << x << " ";
        cot <<"\np = " << p << "\n";*/
        if (p >= s.size() || n->val != s[p]){
            //cout << "loose \n";
            return false;
            
        }
        else
        {
            if (!n->left && !n->right)
            {
                if (p == s.size()-1)
                    return true;
                else
                    return false;    
            }
            
            
            bool l = false;
            if (n->left) {
                l = f(n->left, s, p+1);
            }
            bool r = false;
            if (n->right) {
                r = f(n->right, s, p+1);
            }
            return r || l;            
        }
        
    }
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return f(root, arr, 0);   
    }
};
