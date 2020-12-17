#include <bits/stdc++.h>

using namespace std;
bool valid(unordered_map<char, int>& g, int n)
{
    return !(g['A']>n || g['C']>n || g['G']>n || g['T']>n);
}
// Complete the steadyGene function below.
int steadyGene(string gene) {
    int n = gene.size() / 4;
    int S = 0;
    unordered_map<char, int> g;
    g['A'] = 0;
    g['C'] = 0;
    g['G'] = 0;
    g['T'] = 0;
    while (S < gene.size()) {
        if (g[gene[S]] == n)
            break;
        g[gene[S]]++;
        ++S;
    }
    S--;
    
    g['A'] = 0;
    g['C'] = 0;
    g['G'] = 0;
    g['T'] = 0;
    int T = gene.size()-1;
    while (T >= 0) {
        if (g[gene[T]] == n)
            break;
        g[gene[T]]++;
        --T;
    }
    

    int res = gene.size();
    int s = 0, t = T;
    while (1)
    {
        if (s > t)
            return 0;
        
        while (s < S && valid(g, n)) {
            g[gene[s]]++;
            ++s;
        }
        
        if (!valid(g, n)) {
            --s;
            g[gene[s]]--;
        }
        
        res = min(res, t-s+1);
     
        ++t;
        if (t < gene.size()) {
            g[gene[t]]--;
        } else {
            break;
        }
    }
    return res;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string gene;
    getline(cin, gene);

    int result = steadyGene(gene);

    fout << result << "\n";

    fout.close();

    return 0;
}

