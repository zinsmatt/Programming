class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        auto a1 = (ax2-ax1)*(ay2-ay1);
        auto a2 = (bx2-bx1)*(by2-by1);
        
        int inter = std::max(0, (std::min(ax2, bx2) - std::max(ax1, bx1))) * std::max(0, (std::min(ay2, by2) - std::max(ay1, by1)));
        return a1 + a2  - inter;
        
    }
};
