class Solution {
public:
    int numTilePossibilities(string tiles) {
        std::unordered_set<string> s;
        for (unsigned int i = 1; i < std::pow(2, tiles.size()); ++i) {
            stringstream temp;
            //std::cout << i <<"\n";
            for (int j = 0; j < tiles.size(); ++j) {
                if ((i >> j) & 1u) {
                    temp << tiles[j];
                }
            }
            auto ss = temp.str();
            sort(ss.begin(), ss.end());
            
            do {
                s.insert(ss);
            } while(next_permutation(ss.begin(), ss.end()));
            
        }
        //for (auto x : s) std::cout << x << "\n";
        return s.size();
    }
};
