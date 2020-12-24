#include <bits/stdc++.h>

using namespace std;

// Complete the quickestWayUp function below.
int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
    std::vector<int> g(101, -1);
    for (auto& l : ladders)
    {
        g[l[0]] = l[1];
    }
    for (auto& l : snakes)
    {
        g[l[0]] = l[1];
    }
    std::vector<bool> done(101, false);
    std::queue<int> q({1});
    std::queue<int> n({0});
    int res = -1;
    while (q.size())
    {
        auto x = q.front();
        q.pop();
        auto m = n.front();
        n.pop();
        if (x == 100)
        {
            res = m;
            break;
        }
        done[x] = true;
        for (int i = 1; i < 7; ++i)
        {
            if (g[x+i] != -1)
            {
                q.push(g[x+i]);
                n.push(m+1);
            }
            else if (x+i <= 100 && !done[x+i])
            {
                q.push(x+i);
                n.push(m+1);
            }
        }        
    }
    
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> ladders(n);
        for (int i = 0; i < n; i++) {
            ladders[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> ladders[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int m;
        cin >> m;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> snakes(m);
        for (int i = 0; i < m; i++) {
            snakes[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> snakes[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int result = quickestWayUp(ladders, snakes);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

