class Solution {
public:
    string sortString(string s) {
        stringstream ss;
        while (1)
        {
            unsigned char prev = 0;
            while (1)
            {
                int i = 0;
                unsigned char mini = 255;

                int index = 0;
                for (int i = 0; i < s.size(); ++i)
                {
                    auto& c = s[i];
                    if (c < mini && c > prev && c !='_')
                    {
                        mini = c;
                        index = i;
                    }
                    //cout << "=> " << mini << " _ " << (int) prev << "\n";
                }
                if (mini == 255)
                    break;
                ss << mini;
                prev = mini;   
                //cout << (int) mini << "\n";
                //cout << (int) prev << "\n";


                s[index] = '_';
                //cout << ss.str() << "\n";
            }

            prev = 255;
            while (1)
            {
                int i = 0;
                unsigned char maxi = 0;
                int index = 0;
                for (int i = 0; i < s.size(); ++i)
                {
                    auto& c = s[i];
                    if (c > maxi && c < prev && c !='_')
                    {
                        maxi = c;
                        index = i;
                    }
                }
                if (maxi == 0)
                    break;
                ss << maxi;
                prev = maxi;         
                s[index] = '_';
            }
            
            bool stop = 1;
            for (auto x : s)
                if (x != '_')
                    stop = 0;
            if (stop)
                break;
        }
        
        return ss.str();
    }
};
