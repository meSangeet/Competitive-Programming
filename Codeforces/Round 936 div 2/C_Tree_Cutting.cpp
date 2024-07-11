#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pub push_back
#define pob pop_back
#define pof pop_front
#define puf push_front
#define mp make_pair
#define vi vector<ll>
#define vp vector<pair<ll,ll>>
#define vii vector<vi>
#define vd vector<ld>
#define vb vector<bool>
#define pll pair<ll,ll>
#define maxint 2147483647
#define minint -2147483648
#define endl '\n'
#define rep(x,start,end) for(ll x = start; x < end; x++)
#define rrep(x,start,end) for(ll x = start; x >= end; x--)
#define read(x) rep(i, 0, x.size()) cin >> x[i]
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define py cout << "YES" << endl
#define pn cout << "NO" << endl
#define pyn(x) if(x) py; else pn
#define coe(x) ll odd = 0, even = 0; rep(i, 0, x.size()) {if(x[i] % 2 == 0) even++; else odd++;}
#define c01(x) ll zero = 0, one = 0; rep(i, 0, x.size()) {if(x[i] == 0) zero++; else one++;}
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define F first
#define S second
using namespace std;

ll mod1 = 1e9 + 7, mod2 = 998244353;

template<typename T> void p(T t, bool newln = true){
    cout << t;
    if(newln) cout << endl;
    else cout << " ";
}

template<typename T> void p(vector<T> t){
    rep(i, 0, sz(t)) p(t[i], false);
    cout << endl;
}

template<typename T, typename U> void p(pair<T, U> t){
    p(t.F, false);
    p(t.S);
}

void dfs(ll u, vector<vector<ll>> &adj, vector<ll> &outDegree, ll parent) {
    outDegree[u] = 1; // Include the node itself
    for (ll v : adj[u]) {
        if (v != parent) {
            dfs(v, adj, outDegree, u);
            outDegree[u] += outDegree[v];
        }
    }
}

void calculateSubtreeSize(vector<vector<ll>> &adj, vector<ll> &outDegree) {
    ll n = adj.size();
    dfs(1, adj, outDegree, 0); // Assuming root is at node 1
}
//try to find x such that n/(k+1)>=x


bool f(int x,int n,int k){
 return (n/(k+1)>=x);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc=1;
    cin>>tc;
    while(tc--){
        int n,k;
        cin>>n>>k;

        vector<vector<ll>> adj(n-1);

        rep(i,0,n-1){
            int u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].pub(v);
            adj[v].pub(u);
        }

        int lo=1,hi=1e9;
        
        while(hi-lo>1){
            ll mid=(lo+hi)/2;

            if(f(mid,n,k)){
                lo=mid;
            } else {
                hi=mid;
            }
        }

        cout<<lo<<"\n";
    }
}
