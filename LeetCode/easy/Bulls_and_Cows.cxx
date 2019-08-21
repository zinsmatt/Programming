class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        for (int i = 0; i < secret.size(); ++i)
        {
            if (secret[i] == guess[i])
                bulls++;
        }
        
        std::vector<int> contains(10, 0);
        for (auto const& c : guess)
        {
            contains[c -'0']++;
        }
        
        int cows = 0;
        for (auto const& c : secret)
        {
            if (contains[c - '0'] > 0)
            {
                contains[c - '0']--;
                cows++;
            }
        }
        cows -= bulls;
        std::stringstream ss;
        ss << bulls << "A" << cows << "B";
        return ss.str();
    }
};