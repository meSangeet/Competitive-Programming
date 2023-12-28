#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int weight;
};


int dijkstra(int start, int end, vector<vector<Edge>>& graph, vector<int>& slowness) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> distance(graph.size(), vector<int>(1001, INT_MAX));

    pq.push({0, {start, slowness[start]}});
    distance[start][slowness[start]] = 0;

    while (!pq.empty()) {
        int u = pq.top().second.first;
        int currentSlowness = pq.top().second.second;
        int dist = pq.top().first;
        pq.pop();

        if (dist > distance[u][currentSlowness]) continue;

        for (const Edge& e : graph[u]) {
            int v = e.to;
            int w = e.weight * currentSlowness;

            int newSlowness = min(currentSlowness, slowness[v]);
            if (distance[v][newSlowness] > distance[u][currentSlowness] + w) {
                distance[v][newSlowness] = distance[u][currentSlowness] + w;
                pq.push({distance[v][newSlowness], {v, newSlowness}});
            }
        }
    }

    int minTime = INT_MAX;
    for (int i = 1; i <= 1000; ++i) {
        minTime = min(minTime, distance[end][i]);
    }

    return minTime;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<Edge>> graph(n + 1);
        vector<int> slowness(n + 1);

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        for (int i = 1; i <= n; ++i) {
            cin >> slowness[i];
        }

        int shortestTime = dijkstra(1, n, graph, slowness);
        cout << shortestTime << endl;
    }

    return 0;
}