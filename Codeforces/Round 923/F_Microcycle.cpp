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



void solve() {
    	int n,m;
	cin>>n>>m;
	
	vector<array<int,3>> edges(m);
	vector<vector<int>> adj(n);
	for(int i=0; i<m; i++)
	{
		cin>>edges[i][1]>>edges[i][2]>>edges[i][0];
		edges[i][1]--; edges[i][2]--;
		
		adj[edges[i][1]].push_back(edges[i][2]);
		adj[edges[i][2]].push_back(edges[i][1]);		
	}
	
	sort(edges.rbegin(),edges.rend());
	
	vector<int> parent(n);
	vector<int> rank(n);
	vector<int> prev(n);
	vector<int> ans(n,1e7);
	for(int i=0; i<n; i++) {
		parent[i] = i;
		prev[i] = i;
	}
	
	
	function<int(int)> find = [&](int node)
	{
		if(parent[node]==node) return node;
		return parent[node] = find(parent[node]);
	};
	
	auto merge = [&](int x, int y, int w)
	{
		x = find(x); y = find(y);
		if(rank[x]<rank[y])
		{
			swap(x,y);
		}
		ans[x] = min(ans[x],w);
		prev[y] = x;
		parent[y] = x;
		rank[x]++;
	};
	
	
	vector<int> visited(n);
	vector<int> res;
	function<bool(int,int)> dfs = [&](int node, int des)
	{
		// debug(node);
		if(node==des)
		{
			res.push_back(node);
			return 1;
		}
		for(auto &ch: adj[node])
		{
			if(visited[ch]) continue;
			visited[ch] = 1;
			if(dfs(ch,des))
			{
				res.push_back(node);
				return 1;
			}
		}
		return 0;
	};
	
	// debug(edges);
	map<int, pair<int,int>> mp;
	for(auto e: edges)
	{
		int u = e[1];
		int v = e[2];
		int w = e[0];
		
		int pu = find(u);
		int pv = find(v);
		
		if(pu==pv)
		{
			mp[w] = {u,v};
		}
		else
		{
			merge(pu,pv,w);
		}
	}
	
	// debug(mp);
	
	auto it = mp.begin();
	
	int src = (*it).second.first;
	int des = (*it).second.second;
	
	for(int i=0; i<adj[src].size(); i++)
	{
		if(adj[src][i]==des)
		{
			swap(adj[src][i],adj[src].back());
			adj[src].pop_back();
			break;
		}
	}
	for(int i=0; i<adj[des].size(); i++)
	{
		if(adj[des][i]==des)
		{
			swap(adj[des][i],adj[des].back());
			adj[des].pop_back();
			break;
		}
	}
	
	int weight = (*it).first;
	visited[src] = 1;
	dfs(src,des);
	
	// debug(res);
	
	cout<<weight<<" "<<res.size()<<"\n";
	for(auto &x: res)cout<<x+1<<" ";
	cout<<"\n";
}

int main() {
    FAST;
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}