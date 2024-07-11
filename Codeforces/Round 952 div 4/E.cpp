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
    ll x,y,z,k; cin>>x>>y>>z>>k;
    if((x*y*z)<k)
    {
        cout<<0<<'\n';
        return;
    }
    vector<ll> v = {x,y,z};
    sort(all(v));
    ll maxi = 0;
    for(ll a = 1; a <= cbrt(k); a++)
    {
        if((k%a) == 0){
        for(ll b = 1; b <= sqrt(k); b++)
        {
            if((k%(a*b))==0){
                ll o = k/(a*b);
                    vector<ll> tt = {a,b,o};
                    sort(all(tt));
                    bool flag = false;
                    for(int i = 0; i<3; i++)
                    {
                        if(tt[i]>v[i])
                        {
                            flag = true;
                        }
                    }
                    ll temp = (v[0]-tt[0]+1)*(v[1]-tt[1]+1)*(v[2]-tt[2]+1);
                    if(!flag)
                    {
                        maxi = max(temp, maxi);
                    }
                
            }
        }
        }
    }
    p(maxi);
}

int main() {
    FAST;
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}