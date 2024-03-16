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
    ll n; cin>>n;
    vi a(n);
    bool flag = true;
    ll count = 0;
    unordered_map<ll,ll> m;
    for(int i = 0; i<n; i++)
    {
        cin>>a[i];
        if(a[i] == 0)
        {
            count++;
            flag = false;
            int p = 1;
        }
        m[a[i]]++;
    }

    if(count == 1)
    {
        cout<<-1<<"\n";
        return;
    }
    
    int p = 1;

    if(flag)
    {
        cout<<n<<"\n";
        for(int i = 1; i<=n; i++) cout<<i<<" "<<i<<"\n";
        return;
    }else{
        while(m[p] >= 2)
        {
            p++;
        }
        if(m[p] == 1)
        {
            cout<<-1<<"\n";
            return;
        }
    }

    unordered_map<ll,ll> aa,bb;
    int fi = -1;
    bool f = true;
    for(int i = 0; i<n; i++)
    {
        if(a[i] < p && f)
        {
            aa[a[i]]++;
        }

        if(f && aa.size() == p)
        {
            f = false;
            fi = i+1;
        }

        if(!f && a[i] < p)
        {
            bb[a[i]]++;
        }
    }

    if(bb.size() != p)
    {
        cout<<-1<<"\n";
    }else{
        cout<<2<<"\n";
        cout<<1<<" "<<fi<<"\n";
        cout<<fi+1<<" "<<n<<"\n";
    }
  
}

int main() {
    FAST;
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}