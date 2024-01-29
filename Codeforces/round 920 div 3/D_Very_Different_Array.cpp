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
    ll n,m; cin>>n>>m;
    vi a(n), b(m);
    read(a); read(b);
    // vi c(a);
    sort(all(a));
   sort(all(b));

   int s = 0;

   ll ans = 0;

   int i = 0;
   while(i < a.size())
   {
    vi temp(4);
    temp[0] = abs(a[i]-b[s]);
    temp[1] = abs(a[i]-b.back());
    temp[2] = abs(a.back()-b[s]);
    temp[3] = abs(a.back()-b.back());
    ll curr = INT_MIN; int ind;

    for(int j = 0; j<4; j++)
    {
        if(temp[j]>curr)
        {
            ind = j;
            curr = temp[j];
        }
    }

    if(ind == 0)
    {
        i++;
        s++;
    }

    if(ind == 1)
    {
        i++;
        b.pop_back();
    }

    if(ind == 2)
    {
        a.pop_back();
        s++;
    }

    if(ind == 3)
    {
        a.pop_back();
        b.pop_back();
    }

    ans += curr;
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