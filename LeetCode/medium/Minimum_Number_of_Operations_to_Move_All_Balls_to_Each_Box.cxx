class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> left(boxes.size());
        vector<int> right(boxes.size());
        int c = 0;
        int d = 0;
        for (int i = 0; i < left.size(); ++i) {
            if (i > 0)
                left[i] = left[i-1] + c;
            if (boxes[i] == '1')
                c++;
            
            if (i > 0)
                right[boxes.size()-1-i] = right[boxes.size()-i] + d;
            if (boxes[boxes.size()-1-i] == '1')
                d++;
        }
        for (int i = 0; i < boxes.size(); ++i) {
            left[i] += right[i];
        }
        return left;
    }
};
