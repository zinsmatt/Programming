class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, numeric_limits<int>::max());
        queue<int> q1;
        q1.push(node1);
        dist1[node1] = 0;
        while (!q1.empty()) {
            auto x = q1.front();
            q1.pop();

            if (edges[x] != -1) {
                if (dist1[edges[x]] == numeric_limits<int>::max()) {
                    dist1[edges[x]] = dist1[x] + 1;
                    q1.push(edges[x]);
                }
            }
        }

        vector<int> dist2(n, numeric_limits<int>::max());
        queue<int> q2;
        q2.push(node2);
        dist2[node2] = 0;
        while (!q2.empty()) {
            auto x = q2.front();
            q2.pop();

            if (edges[x] != -1) {
                if (dist2[edges[x]] == numeric_limits<int>::max()) {
                    dist2[edges[x]] = dist2[x] + 1;
                    q2.push(edges[x]);
                }
            }
        }


        int dmax = numeric_limits<int>::max();
        int idx = -1;
        for (int i = 0; i < n; ++i) {
            int d = max(dist1[i], dist2[i]);
            if (d < dmax) {
                dmax = d;
                idx = i;
            }
        }

        return idx;

        
    }
};
