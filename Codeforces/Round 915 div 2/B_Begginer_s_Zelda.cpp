#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n; cin>>n;
    vector<vector<int>> adj(n);

    for(int i = 0; i < n - 1; i++)
    {
        int a, b; 
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    int leaf_nodes = 0;
    for (int i = 0; i < n; ++i) {
        if (adj[i].size() == 1) { 
           leaf_nodes++;
        }
    }

    if(leaf_nodes%2 == 0)
    {
        cout<<leaf_nodes/2<<endl;
    }else{
        cout<<leaf_nodes/2+1<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}