#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);



int main()
{
    int road_nodes;
    int road_edges;
    
    

    cin >> road_nodes >> road_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> road_from(road_edges);
    vector<int> road_to(road_edges);
    vector<int> road_weight(road_edges);


    for (int i = 0; i < road_edges; i++) {
        cin >> road_from[i] >> road_to[i] >> road_weight[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    vector<vector<int>> W(road_nodes, vector<int>(road_nodes, -1));
    for (int i = 0; i < road_from.size(); ++i)
    {
        W[road_from[i]-1][road_to[i]-1] = road_weight[i];
    }
    for (int i = 0; i < road_nodes; ++i)
    {
        W[i][i] = 0;
    }
    
    for (int k = 0; k < road_nodes; ++k)
    {
        for (int i = 0; i < road_nodes; ++i)
        {
            for (int j = 0; j < road_nodes; ++j)
            {
                if (W[i][k] >= 0 && W[k][j] >= 0)
                {
                    if (W[i][j] < 0 || W[i][k]+W[k][j] < W[i][j])
                    {
                        W[i][j] = W[i][k] + W[k][j];
                    }
                }
            }
        }
    }

    
    

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string xy_temp;
        getline(cin, xy_temp);

        vector<string> xy = split_string(xy_temp);

        int x = stoi(xy[0]);

        int y = stoi(xy[1]);
        
        std::cout << W[x-1][y-1] << "\n";
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
