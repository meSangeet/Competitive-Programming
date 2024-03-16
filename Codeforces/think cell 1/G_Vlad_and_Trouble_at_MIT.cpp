#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];
char type[MAXN];
int thick_walls;

pair<int, int> dfs(int u, int parent) {
    int party = 0;
    int sleep = 0;
    
    for (int v : adj[u]) {
        pair<int, int> result = dfs(v, u);
        party += result.first;
        sleep += result.second;
    }

    if (type[u] == 'P' && sleep > 0) {
        thick_walls++;
        party = sleep = 0; // Reset counts to avoid counting in parent nodes
    }

    if (type[u] == 'P') party++;
    else if (type[u] == 'S') sleep++;

    return {party, sleep};
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            type[i] = 'C';
        }

        for (int i = 2; i <= n; i++) {
            int a;
            cin >> a;
            adj[i].push_back(a);
        }

        for (int i = 1; i <= n; i++) {
            cin >> type[i];
        }

        thick_walls = 0;
        dfs(1, -1);

        cout << thick_walls << endl;
    }

    return 0;
}
