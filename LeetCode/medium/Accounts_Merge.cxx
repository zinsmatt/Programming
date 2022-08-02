
class Solution {

vector<int> parent;

void funion(int x, int y) {
	auto px = find(x);
	auto py = find(y);
	if (px != py) {
		parent[px] = py;
	}
}

int find(int x) {
	if (parent[x] == -1)
		return x;
	parent[x] = find(parent[x]);
    return parent[x];
}

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
       	std::unordered_map<string, vector<int>> m;
        for (int i = 0; i < accounts.size(); ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                auto& a = accounts[i][j];
                if (m.count(a)) {
                    m[a].push_back(i);
                } else {
                    m[a] = {i};
                }
            }           
        }
        parent.resize(accounts.size(), -1);

        for (auto& it : m) {
            for (int j = 1; j < it.second.size(); ++j) {
                funion(it.second[j], it.second[0]);
            }
        }

        std::unordered_map<int, std::unordered_set<string>> unique;
        for (int i = 0; i < parent.size(); ++i) {
            auto x = find(i);
            if (unique.count(x) == 0) {
                unique[x] = std::unordered_set<string>();
            }
            for (int j = 1; j < accounts[i].size(); ++j) {
                auto& s = accounts[i][j];
                unique[x].insert(s);
            }	
        }

        vector<vector<string>> res;
        for (auto& it : unique) {
            vector<string> adr = {accounts[it.first][0]};
            for (auto x : it.second) {
                adr.push_back(x);
            }
            sort(adr.begin()+1, adr.end());
            res.push_back(std::move(adr));
        }
        return res;
    }

	
};

