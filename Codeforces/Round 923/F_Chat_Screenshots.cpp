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
    int n, k;
        cin >> n >> k;
        
        deque<int> v;
        bool flag = true;
        ll cnt = 0;
        for(int i = 0; i<k; i++)
        {
            ll ind = 0;
                    ll tt = 0;
                    ll q = 0;
            for(int j = 0; j<n; j++)
            {
                int p; cin>>p;
                if(i == 0)
                {
                    if(j > 0)
                    v.push_back(p);
                    else cnt = p;
                }else if (i == 1){
                    if(j == 0)
                    {
                        tt = p;
                    }else{
                        if(p == cnt)
                        {
                            v.insert(v.begin()+j, p);
                            for(auto x:v) cout<<x<<" ";
                            cout<<"\n";
                            ind++;
                        }
                        if(!q && v[ind] == tt)
                        {
                            q = 1;
                            ind++;
                        }else
                        {
                            if(v[ind] != p)
                            {
                                cout<<i<<" "<<j<<" "<<ind<<endl;
                                flag = false;
                            }
                            ind++;
                        }
                    }
                }else{
                    if(j == 0)
                    {
                        tt = p;
                    }else{
                        if(!q && v[ind] == tt)
                        {
                            q = 1;
                            ind++;
                        }else
                        {
                            if(v[ind] != p)
                            {
                                // cout<<i<<" "<<j<<" "<<ind<<endl;
                                flag = false;
                            }
                            if(i == 2) cout<<ind<<" ";
                            ind++;
                        }
                    }
                }
            }
        }

        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
}

int main() {
    FAST;
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}