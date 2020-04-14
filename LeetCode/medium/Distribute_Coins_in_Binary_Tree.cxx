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
    
    int moves = 0;
    
    int solve(TreeNode* n)
    {
        if (!n)
            return 0;
        int left = solve(n->left);
        int right = solve(n->right);
        moves += abs(left) + abs(right);
        return left + right + n->val - 1;
    }
        
    int flood_forward(TreeNode* r, int c)
    {
        if (r)
        {   
            cout << "push " <<c << "\n";
            int total = r->val + c;
            if (total >= 1)
                r->val = 1;
            int available = max(0, total-1);
            cout << "available = " << available<<"\n";
            auto ret_left = flood_forward(r->left, available);
            cout << "ret left " << ret_left << "\n";
            moves += max(0, available - ret_left);
            auto ret_right = flood_forward(r->right, ret_left);
            cout << "ret right " << ret_right << "\n";
            moves += max(0, ret_left - ret_right);
            cout << "return  " << max(0, c-ret_right) << "\n";
            
            auto return_val = max(0, c-ret_right);
            r->val += ret_right-return_val;
            return return_val;
            
        }
        return c;
    }
        
    
    int flood_backward(TreeNode* r)
    {
        if (r)
        {
            auto rval_init =r->val;
            auto total = r->val;
            cout << "total = " << total << "\n";
            auto res = flood_backward(r->left);
            cout << "res from left " << res << "\n";
            total += res;
            moves += res;
            res = flood_backward(r->right);
            cout << "res from right " << res << "\n";
            moves += res;
            total += res;
            
            r->val += total;
            
            if (total >= 1)
            {
                cout << "return " << total << "\n";
                return rval_init;
            }
            else
            {
                cout << "return " << 0 << "\n";
                return 0;
            }
        }
        return 0;
    }
    
    
    int f_down(TreeNode* n)
    {
        if (n && this->down)
        {
            auto l = f_down(n->left);
            auto r = f_down(n->right);
            if (this->down && n->val > 0)
            {
                if (l < 0)
                {
                    n->left->val++;
                    n->val--;
                    down = false;
                    moves++;
                }
                else if (r < 0)
                {
                    n->right->val++;
                    n->val--;
                    down = false;
                    moves++;
                }
            }
            return l+r+n->val-1;
        }
        return 0;
    }
    
    
    int f_up(TreeNode* n)
    {
        if (n && this->up)
        {
            auto l = f_up(n->left);
            auto r = f_up(n->right);
            
            if (this->up)
            {
                if (l > 1)
                {
                    n->val++;
                    n->left->val--;
                    up = false;
                    moves++;
                }
                else if (r > 1)
                {
                    n->val++;
                    n->right->val--;
                    up = false;
                    moves++;
                }
            }
            return n->val;
        }
        return 0;
    }
    
    
    int max_node(TreeNode* r)
    {
        if (r)
        {
            auto a = max_node(r->left);
            auto b = max_node(r->right);
            return max(r->val, max(a, b));
        }
        return 0;
    }
        
    void print(TreeNode* n)
    {
        if (n)
        {
            cout << n->val << " ";
            print(n->left);
            print(n->right);
        }
        else
            cout << "null ";
        
        
    }

    
    bool down = true;
    bool up = true;
    
    void process(TreeNode *root)
    {
        int max = 0;
        do 
        {
            int save_moves;
            //cout << "down\n";
            do
            {
                save_moves = moves;
                down = true;
                f_down(root);
                //print(root);cout << "\n";
            } while (save_moves != moves);
                        
            save_moves = moves;
            //cout << "up\n";
            do{
                save_moves = moves;
                up = true;
                f_up(root);
                //print(root);cout << "\n";
            } while (save_moves != moves);

            max = max_node(root);
            
        } while (max != 1);
    }
    
public:
    int distributeCoins(TreeNode* root) {        
        moves = 0;
        solve(root);
        
        return moves;
    }
};
