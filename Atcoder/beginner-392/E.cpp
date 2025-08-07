#include <bits/stdc++.h>
using namespace std;
#define ll long long

class DSU {
private:
    vector<ll> parent, rank, size;
    ll sz;
public:
    DSU(ll n) {
        sz = n;
        parent.resize(n + 2);
        rank.resize(n + 2, 1);
        size.resize(n + 2, 1);
        for (ll i = 1; i <= n; i++) { 
            parent[i] = i;
        }
    }
    ll find(ll x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }
    void unite(ll x, ll y) {
        ll rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
                size[rootX] += size[rootY];
            }
        }
    }
    bool sameSet(ll x, ll y) {
        return find(x) == find(y);
    }
    ll getSize(ll x) {
        return size[find(x)];
    }
    ll countSets() {
        ll count = 0;
        for (ll i = 1; i <= sz; i++) { 
            if (find(i) == i) {
                count++;
            }
        }
        return count;
    }
};

void solve() {
    ll n, m;
    cin >> n >> m;
    DSU ds(n);
    vector<vector<ll>> extraEdges;

    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        if (ds.sameSet(a, b)) {
            extraEdges.push_back({i + 1, a, b});
        } else {
            ds.unite(a, b);
        }
    }

    set<ll> componentBaap;
    for (ll i = 1; i <= n; i++) {
        if (ds.find(i) == i) {
            componentBaap.insert(i);
        }
    }

    cout << max((ll)(componentBaap.size() - 1), (ll)0) << endl;

    ll ind = 0;

    while ((ll)componentBaap.size() > 1 and ind < extraEdges.size()) {
        auto ee = extraEdges[ind];
        ll n1 = ee[1];
        ll n2 = ee[2];
        ll rem = -1;
        
        for (ll baap : componentBaap) {

            if (!ds.sameSet(n1, baap)) {
                cout << ee[0] << " " << n1 << " " << baap << endl;
                rem = baap;
                ds.unite(n2, baap);
                break;
            }
            if (!ds.sameSet(n2, baap)) {
                cout << ee[0] << " " << n2 << " " << baap << endl;
                rem = baap;
                ds.unite(n1, baap);
                break;
            }
        }
        ind++;
        if (rem != -1) {
            componentBaap.erase(rem);
        }
    }
}

int main() {
    int t = 1;
    while (t--) solve();
    return 0;
}
