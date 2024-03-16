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

ll calc(ll sz)
{
    ll ans = 0;
    if(sz%2)
        {
            ll temp = sz-1;
            temp/=2;
            ans += (temp)*(temp+1);
            ans+=sz/2+1;
        }else{
            ll temp=sz/2;
            ans += temp*(temp+1);
        }

    return ans;
}

int func(string s, int i, int j)
{
    vi a(j-i+1,0);
    int szz = j-i+1;
    int ans = 0;
    if(szz == 1)
    {
        if(s[i] == '1') return 1;
    }
    for(int p = i; p<=j; p++)
    {
        if(s[p] == '1')
        {
            if(p == i)
            {
                a[p] = 1;
                ans++;
            }else{
                if(s[p-1] == 1)
                {
                    s[p] == 2;
                }
            }
        }
    }
}
void solve() {
    ll n; cin>>n;
    string s; cin>>s;
    ll ans = 0;
    ll curr = 0;
    ll siz = 0;
    ll lz = -1;
    vi a(n,0);

    for(int i = n-1; i>=0; i--)
    {
        if(s[i] == 1)
        {
            if(lz = -1)
            {
                lz = i;
                ans++;
            }else{
                if(lz > i+1)
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