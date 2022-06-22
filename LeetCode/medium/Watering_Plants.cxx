class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int res = 0;
        int k = capacity;
        for (int i = 0; i < plants.size(); ++i) {
            if (k >= plants[i]) {
                res++;
                
            } else {
                res += i*2+1;
                k = capacity;
            }
            
            k -= plants[i];
            
        }
        return res;
        
    }
};
