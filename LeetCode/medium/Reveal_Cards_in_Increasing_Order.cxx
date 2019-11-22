class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        vector<int> res(deck.size());
        vector<int> places(deck.size());
        iota(places.begin(), places.end(), 0);
        f(deck, res, 0, places, 0);
        return res;
    }
    
    void f(vector<int> const& val, vector<int>& res, int a, vector<int> places, int o)
    {
        int count_left = places.size();
        int n = (int)std::ceil((float)(count_left-o) / 2);
        
        for (int i = 0; i < n; ++i)
        {
            int idx = (o+2*i) % places.size();
            res[places[idx]] = val[a++];
            places[idx] = -1;
        }
       
        if (places.back() == -1)
        {
            o = 1;
        }
        else
        {
            o = 0;
        }
        
        
        vector<int> new_places;
        for (auto p : places)
            if (p != -1)
                new_places.push_back(p);
                
        if (a < val.size())
            f(val, res, a, new_places, o);
    }
};