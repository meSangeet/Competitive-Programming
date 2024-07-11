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
    ll n,m,k; cin>>n>>m>>k;
    string s; cin>>s;
    vector<ll> a(n),b(n);
    a[n-1] = n; b[n-1] = INT_MAX;
    for(int i = n-2; i>=0; i--)
    {
        if(s[i+1] == 'L')
        {
            a[i] = i+1;
        }else{
            a[i] = a[i+1];
        }

        if(s[i+1] == 'C')
        {
            b[i] = i+1;
        }else{
            b[i] = b[i+1];
        }
    }

    int c = 0;
    ll sw = 0;
    if(s[0] != 'L')
    {
        if(a[0] <= m-1)
        {
            c = a[0];
        }else{
            if(s[m-1] == 'C')
            {
                pn;
                return;
            }else{
                c = m-1;
                if(b[c] < a[c])
                {
                    pn;
                    return;
                }else{
                    sw += a[c]-c;
                    c = a[c];
                }
            }
        }
    }
    if(sw > k)
    {
        pn;
        return;
    }
    // cout<<c<<endl;
    while(c < n)
    {
        ll nl = a[c];
        ll nc = b[c];
        // if(c == 3)
        // {
        //     cout<<nl<<" "<<nc<<endl;
        // }
        if(nc < nl)
        {
            if((nl-c) <= m)
            {
                c = nl;
            }else{
                if((nc-c) >= m)
                {
                    pn;
                    return;
                }else{

                    c = c+m;
                    if(s[c] == 'C')
                    {
                        pn;
                        return;
                    }
                    if(b[c] < nl)
                    {
                        pn;
                        return;
                    }else{
                        sw += nl - c;
                        c = nl;
                    }
                }
            }
        }else{
            if((nl-c) > m)
            {
                sw += (nl-c-m);
                if(m == 0) sw--;
                c = nl;
            }else{
                c = nl;
            }
        }
        // cout<<c<<" "<<sw<<endl;
        if(sw > k)
        {
            pn;
            return;
        }
    }

    py;

    // rep(i,0,n)
    // {
    //     cout<<a[i]<<" "<<b[i]<<endl;
    // }
}

int main() {
    FAST;
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}