class Solution {
public:
    int calPoints(vector<string>& ops) {
        std::vector<int> scores;
        int sum = 0;
        for (auto const & s : ops)
        {
            if (s == "+")
            {
                scores.push_back(scores[scores.size()-1] + scores[scores.size()-2]);
                sum += scores.back();
            }
            else if (s == "D")
            {
                scores.push_back(scores.back()*2);
                sum += scores.back();
            }
            else if (s == "C")
            {
                sum -= scores.back();
                scores.erase(scores.end()-1);              
            }
            else
            {
                scores.push_back(std::stoi(s));
                sum += scores.back();
            }
        }
        return sum;
    }
};