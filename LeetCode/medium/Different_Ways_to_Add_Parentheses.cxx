class Solution {
    struct Node {
        long long val;
        char op;
        string s;
        Node* prev;
        Node* next;
        Node(int v) : val(v), prev(nullptr), next(nullptr), op('?'), s("") {}
        Node(char o) : val(0), prev(nullptr), next(nullptr), op(o), s("") {}
        Node(Node* n) : val(n->val), prev(nullptr), next(nullptr), op(n->op), s(n->s) {}
    };
    
    Node* copy_list(Node* head)
    {
        if (!head)
            return nullptr;
        Node* nouv_head = new Node(head);
        Node* cur = nouv_head;
        Node* pt = head->next;
        while (pt)
        {
            Node* nouv = new Node(pt);
            nouv->prev = cur;
            cur->next = nouv;
            cur = nouv;
            pt=pt->next;
        }
        return nouv_head;
    }
    void compute(Node* n)
    {
        //cout << "merge " << n->prev->val << " " << n->op << " " << n->next->val << endl;
        if (!n)
        {
            cout << "Error compute expression op" << endl;
            return;            
        }
        auto* left = n->prev;
        auto* right = n->next;
        if (!left || !right)
        {
            cout << "Error compute expression left right" << endl;
            return;
        }
        long long l = left->val;
        long long r = right->val;
        long long res = 0;
        if (n->op == '+')
        {
            res = l+r;
        }
        else if (n->op == '-')
        {
            res = l-r;
        }
        else if (n->op == '*')
        {
            res = l*r;
        }
        else
        {
            cout << "Error invalid operator" << endl;
            return;
        }
        
        left->val = res;
        left->s = "(" + left->s + n->op + right->s + ")";
        left->next = right->next;
        if (right->next)
            right->next->prev = left;
        delete n;
        delete right;
    }
    
public:
    vector<int> diffWaysToCompute(string expression) {
        int i = 0;
        
        Node* head = new Node(0);
        Node* pt = head;
        vector<int> operators;
        int count = 0;
        while (i < expression.size())
        {
            int j = i+1;
            while (j < expression.size() && expression[j] >= '0' && expression[j] <= '9')
            {
                ++j;
            }
            int x = stoi(expression.substr(i, j-i));
            Node* nouv = new Node(x);
            pt->next = nouv;
            nouv->prev = pt;
            pt = nouv;
            count++;
            
            if (j < expression.size())
            {
                char op = expression[j];
                Node* nouv = new Node(op);
                pt->next = nouv;
                nouv->prev = pt;
                operators.push_back(count);
                pt = nouv;
                count++;
            }
            
            i = j + 1;
        }

        unordered_map<string, int> res;
        vector<int> results;
        vector<int> indices(operators.size());
        iota(indices.begin(), indices.end(), 0);
        //std::cout << indices.size() << "\n";
        do
        {
            // copy list and operators
            Node* list = copy_list(head->next);
            vector<Node*> ops(operators.size(), nullptr);
            for (int i = 0; i < operators.size(); ++i)
            {
                int d = operators[i];
                Node* n = list;
                for (int j = 0; j < d; ++j)
                    n=n->next;
                ops[i] = n;
            }
            
            // compute
            for (auto idx : indices)
            {
                //cout << idx << " " ;
                compute(ops[idx]);
            }
            //cout << "==>" << list->val << " " << list->s << "\n";
            if (res.find(list->s) == res.end())
            {
                res[list->s] = 1;
                results.push_back(list->val);
            }
            
        } while (next_permutation(indices.begin(), indices.end()));
        sort(results.begin(), results.end());

        return results;
    }
};
