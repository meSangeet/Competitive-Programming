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

bool customCompare(const pair<ll, ll> &a, const pair<ll, ll> &b) {
    if (a.first == b.first) {
        return a.second < b.second; // Sort by second element if first element is same
    }
    return a.first < b.first; // Otherwise, sort by first element
}

ll func(vi &starting, vi &ending)
{
    ll n = starting.size();
    vector<pair<ll,ll>> v;
    for(int i = 0; i<n; i++)
    {
        v.push_back({starting[i],ending[i]});
    }
    sort(all(v), customCompare);
    ll cnt = 0;
    ll last = 0;
    ll ans = 0;
    ll now = 0;
    for(int i = 0; i<n; i++)
    {
        if(v[i].first > last)
        {
            cnt++;
            last = v[i].second;
        }else{
            now++;
        }
        if(cnt > 2)
        {
            ans += ((cnt-1)*(cnt-2))/2;
        }
    }
    return ans;
}


void solve() {
    ll n; cin>>n;
    vi starting(n),ending(n);
    read(starting);
    read(ending);
    cout<<func(starting,ending)<<endl;
}

int main() {
    FAST;
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}