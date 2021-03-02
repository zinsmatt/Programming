/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

void g(node* n)
{
    if (!n) {std::cerr<<"NULL "; return;}
    else{ std::cerr << n->val << " ";
         g(n->left); g(n->right);
        }
}
void f(node* n)
{
    if (n)
    {
        std::cout << n->val << " " << n->ht << "\n";
        std::cout << "left : ";
        f(n->left);
        std::cout << "\n";
        std::cout << "right : ";
        f(n->right);
        std::cout << "\n";
    }
}

bool find(node* n, int val, vector<node*>& path)
{
    if (!n) return false;
    if (n->val < val)
    {
        path.push_back(n);
        if (n->right)
        {
            return find(n->right, val, path);
        } 
        else 
        {
            node* nouv = new node();
            nouv->val = val;
            nouv->left = nullptr;
            nouv->right = nullptr;
            nouv->ht = 0;
            n->right = nouv;
            path.push_back(nouv);
            return !n->left;
        }
    }
    else
    {
        path.push_back(n);
        if (n->left)
        {
            return find(n->left, val, path);
        }
        else
        {
            node* nouv = new node();
            nouv->val = val;
            nouv->left = nullptr;
            nouv->right = nullptr;
            nouv->ht = 0;
            n->left = nouv;
            path.push_back(nouv);
            return !n->right;
        }
    }
}

int update_height(node* n)
{
    if (!n) return -1;
    auto lh = update_height(n->left);
    auto rh = update_height(n->right);
    n->ht = 1 + std::max(rh, lh);
    return n->ht;
    
}


node * insert(node * root,int val)
{
    g(root);
    std::cerr << "\n";
    if (!root)
    {
        node* nouv = new node();
        nouv->val = val;
        nouv->left = nullptr;
        nouv->right = nullptr;
        nouv->ht = 0;
        return nouv;
    }

    vector<node*> ancestors;
    auto ret = find(root, val, ancestors);
    
    update_height(root);

/*    if (ret)
    {
        for (int i = 0; i < ancestors.size()-1; ++i)
            ancestors[i]->ht++;
    }*/
    
    vector<int> BF;
    for (auto a : ancestors)
    {
        int hl=-1, hr=-1;
        if (a->left)
            hl = a->left->ht;
        if (a->right)
            hr = a->right->ht;
        BF.push_back(hl-hr);
    }
    /*std::cout << "ret = " << ret << "\n";
    std::cout << "ancestors : ";
    for (auto a : ancestors)
    {
        std::cout << a->val << " ";
    }
    std::cout << std::endl;
    std::cout << "heights : ";
    for (auto a : ancestors)
    {
        std::cout << a->ht << " ";
    }
    std::cout << std::endl;
    std::cout << "BF : ";
    for (auto a : BF)
    {
        std::cout << a << " ";
    }
    std::cout << std::endl;
    */
    
    if (ancestors.size() < 3)
    {
        return root;
    }
    
    int i = ancestors.size()-1;
    while (i >= 0 && BF[i]>=-1 && BF[i] <= 1)
    {
        --i;
    }
    if (BF[i] >= -1 && BF[i] <= 1)
        return root;
    std::cerr << "i stop " << i <<  " " << ancestors[i]->val << std::endl;
     

    int j = i+1;
    int k = j+1;
    node* I = ancestors[i];
    node* J = ancestors[j];
    node* K = ancestors[k];
    std::cerr << "I = " << ancestors[i]->val << "\n";
    std::cerr << "J = " << ancestors[j]->val << "\n";
    std::cerr << "K = " << ancestors[k]->val << "\n";
    if (BF[i] < -1 || BF[i] > 1)
    {
        
        if (BF[i] == 2)
        {
            if (BF[j] == -1)
            {
                std::cerr << "Left Right " << std::endl;
                // Left Right
                I->left = K;
                J->right = K->left;
                K->left = J;
            } else
            {
                std::cerr << "Left Left " << std::endl;
                std::swap(J, K);
                std::swap(j, k);
            }
            // Left Left
            I->left = K->right;
            K->right = I;                    
        } else if (BF[i] == -2)
        {
            if (BF[j] == 1)
            {
                std::cerr << "Right Left" << std::endl;
                // Right Left
                J->left = K->right;
                I->right = K;
                K->right = J;
            } else {
                std::cerr << "Right Right " << std::endl;
                std::swap(J, K);
                std::swap(j, k);
            }
            I->right = K->left;
            K->left = I;
        }
    }
    
    
    if (i == 0)
    {
        std::cerr << " i =) 0 " << std::endl;
        // change root
        update_height(K);
        return K;
    }
    else
    {
        std::cerr << " not change root " << std::endl;

        std::cerr << " K val =) " <<  K->val << std::endl;
        std::cerr << "ancestor-1 val =) " <<  ancestors[i-1]->val << std::endl;
        
        // update parent;
        if (ancestors[i-1]->left == I)
        {
            std::cerr << "to left" << std::endl;
            ancestors[i-1]->left = K;
        } else 
        {
            std::cerr << "to right" << std::endl;
            ancestors[i-1]->right = K;
        }
        update_height(root);
        return root;
    }
  
}
