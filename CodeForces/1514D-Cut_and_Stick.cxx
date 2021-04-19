#include <cmath>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
 
using namespace std;
 
const int MAX = 300005;
const int MAGIC = 333;
 
struct query{
    int l;
    int r;
    int id;
    query() {
        
    }
    query(int l, int r, int id):
    l(l), r(r), id(id) {
        
    }
    bool operator < (const query other) const{
        if(l / MAGIC != other.l / MAGIC) {
            return l / MAGIC < other.l / MAGIC;
        }
        return r < other.r;
    }
};
 
int N, Q;
int a[MAX], output[MAX], counts[MAX], frequencies[MAX];
vector<query> queries;
 
void fix(int &answer) {
    while (frequencies[answer + 1] > 0) {
        answer ++;
    }
    while (answer > 0 && frequencies[answer] == 0) {
        answer --;
    }
}
void add(int position, int &answer) {
    frequencies[counts[a[position]]] --;
    counts[a[position]] ++;
    frequencies[counts[a[position]]] ++;
    fix(answer);
}
void remove(int position, int &answer) {
    frequencies[counts[a[position]]] --;
    counts[a[position]] --;
    if (counts[a[position]] > 0) {
        frequencies[counts[a[position]]] ++;
    }
    fix(answer);
}
 
 
int main(int argc, const char * argv[]) {
    //scanf("%d%d", &N, &Q);
    cin >> N;
    cin >> Q;
    for (int i = 0; i < N; i ++) {
        //scanf("%d", &a[i]);
        cin >> a[i];
    }
    for (int i = 0; i < Q; i ++) {
        int l, r;
        //scanf("%d%d", &l, &r);
        cin >> l;
        cin >> r;
        queries.push_back(query(l-1, r-1, i));
    }
    vector<int> idx(Q);
    std::iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b) {
        return queries[a] < queries[b];
    });
    //sort(queries.begin(), queries.end());
    int L = N - 1, R = N - 1;
    int answer = 0;
    vector<int> results(Q);
    for(int ii = 0; ii < Q; ii++) {
        int i = idx[ii];
 
        for(int j = L; j >= queries[i].l; j --) {
            add(j, answer);
        }
        for(int j = R + 1; j <= queries[i].r; j ++) {
            add(j, answer);
        }
        for(int j = L + 1; j < queries[i].l; j ++) {
            remove(j, answer);
        }
        for(int j = R; j > queries[i].r; j --) {
            remove(j, answer);
        }
        L = queries[i].l - 1;
        R = queries[i].r;
        // output[queries[i].id] = answer;
        auto max = answer;
        // cout << " query " << i << " ==> " << queries[i].l << " " << queries[i].r << "\n";
        // cout << "max = " << max << "\n";
        int N = queries[i].r-queries[i].l+1;
        int res = 1;
        if (max > std::ceil(static_cast<double>(N)/2))
        {
            res = max - (N - max);
        }
        // cout << res << "\n";
        results[i] = res;
    }
    for (auto r : results)
    cout << r << "\n";
    
    return 0;
}
