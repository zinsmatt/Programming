/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
    
    int bin_search(BinaryMatrix& m, int l, int r, int i)
    {
        if (l > r)
            return numeric_limits<int>::max();
        if (l == r)
        {
            if (m.get(i, l) == 1)
                return l;
            else 
                return numeric_limits<int>::max();
        }
        else
        {
            int mid = (l+r) / 2;
            if (m.get(i, mid))
            {
                return bin_search(m, l, mid, i);
            }
            else
            {
                return bin_search(m, mid+1, r, i);
            }
        }
    }
    
public:
    
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto rep = numeric_limits<int>::max();
        auto dim = binaryMatrix.dimensions();
        auto w = dim[1];
        auto h = dim[0];
        
        for (int i = 0; i < h; ++i)
        {
            auto idx = bin_search(binaryMatrix, 0, w-1, i);
            rep = min(rep, idx);
        }
        if (rep >= w)
            rep = -1;
        return rep;
    }
};
