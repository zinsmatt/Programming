/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        std::queue<TreeNode*> q;
        std::queue<int> d;
        q.push(root);
        d.push(1);
        while (q.size() > 0)
        {
            auto * a = q.front();
            q.pop();
            int b = d.front();
            d.pop();
            
            if (!a->left && !a->right)
            {
                return b;
            }
            else
            {
                if (a->left)
                {
                    q.push(a->left);
                    d.push(b+1);
                }
                if (a->right)
                {            
                    q.push(a->right);
                    d.push(b+1);
                }
            }
        }
        return 0;
    }
    
    
};