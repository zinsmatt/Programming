/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize_int(int x)  {
        string res = "0000";
        char* pt = reinterpret_cast<char*>(&x);
        res[0] = pt[0];
        res[1] = pt[1];
        res[2] = pt[2];
        res[3] = pt[3];
        cout << "serialized " << x << " => " << res << endl;
        return res;
    }

    int deserialize_int(const string& s, int i) {
        i*=4;
        char buffer[4];
        buffer[0] = s[i];
        buffer[1] = s[i+1];
        buffer[2] = s[i+2];
        buffer[3] = s[i+3];
        return *reinterpret_cast<int*>(buffer);
    }

    int fill(TreeNode* n, vector<int>& vals, vector<pair<int, int>>& children) {
        if (!n)
            return -1;
        int cur_id = vals.size();
        vals.push_back(n->val);
        children.push_back({-1, -1});
        int idl = fill(n->left, vals, children);
        int idr = fill(n->right, vals, children);
        children[cur_id] = {idl, idr};
        return cur_id;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // n | vals | [left | right] ...
        vector<int> values;
        vector<pair<int, int>> children;
        fill(root, values, children);

        stringstream ss;
        ss << serialize_int(values.size());
        for (auto v : values)
            ss << serialize_int(v);
        for (auto p : children) {
            ss << serialize_int(p.first);
            ss << serialize_int(p.second);
        }
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = deserialize_int(data, 0);
        if (n == 0)
            return nullptr;

        vector<TreeNode*> nodes(n, nullptr);
        for (int i = 0; i < n; ++i) {
            int v = deserialize_int(data, i+1);
            nodes[i] = new TreeNode(v);
        }
        int j = 1+n;
        for (int i = 0; i < n; ++i) {
            int l = deserialize_int(data, j);
            ++j;
            int r = deserialize_int(data, j);
            ++j;
            if (l >= 0)
                nodes[i]->left = nodes[l];
            if (r >= 0)
                nodes[i]->right = nodes[r];
        }
        return nodes[0];        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
