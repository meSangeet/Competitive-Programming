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
    ll a,b,r; cin>>a>>b>>r;
    vi A(64, 0);
    vi B(64, 0);
    // for(auto x:A) cout<<x<<" ";
    // cout<<"\n";
    // for(auto x:B) cout<<x<<" ";
    // cout<<"\n";
    ll p = max(a,b);
    ll q = min(a,b);
    ll ans = p-q;
    for(int i = 0; i<64; i++)
    {
        if(((q>>i)&1))
        {
            A[i] = 1;
        }

        if(((p>>i)&1))
        {
            B[i] = 1;
        }
    }
    vector<pair<ll,ll>> vec;
    for(ll i = 60; i>=0; i--)
    {
        if((A[i] == 0 && B[i] == 1))
        {
            ll temp = (B[i]<<i) - (A[i]<<i);
            vec.pub({temp,i});
        }
    }
    // for(auto x:vec) cout<<x.first<<" "<<x.second<<endl;
    ll val = 0;
    for(auto x:vec)
    {
        ll temp = ans - x.first - x.first;
        if(temp <= ans && temp >= 0)
        {
            ll tt = pow(2ll,x.second) + val;
            if(tt <= r)
            {
                val = tt;
                ans = temp;
            }
        }
    }

    cout<<ans<<"\n";
}

int main() {
    FAST;
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
