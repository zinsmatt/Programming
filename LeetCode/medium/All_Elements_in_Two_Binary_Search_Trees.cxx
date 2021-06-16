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

vector<int> listify(TreeNode* n)
{
    if (!n) return {};
    auto l = listify(n->left);
    l.push_back(n->val);
    auto r = listify(n->right);
    l.insert(l.end(), r.begin(), r.end());
    return l;    
}

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        auto l1 = listify(root1);        
        auto l2 = listify(root2);
        
        vector<int> res;
        int a = 0, b = 0;
        while (a < l1.size() || b < l2.size())
        {
            if (a >= l1.size())
            {
                res.push_back(l2[b++]);
            } else if (b >= l2.size()) {
                res.push_back(l1[a++]);
            } else {
                if (l1[a] < l2[b])
                {
                    res.push_back(l1[a++]);
                } else 
                {
                    res.push_back(l2[b++]);
                }
            }
        }
        return res;
    }
};
