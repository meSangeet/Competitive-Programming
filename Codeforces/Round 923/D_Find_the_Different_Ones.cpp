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
    ll last; 
    vi a(n);
    vi vec;
    for(int i = 0; i<n; i++)
    {
        cin>>a[i];
        if(i > 0)
        {
            if(a[i] != a[i-1])
            {
                vec.pub(i+1);
                // cout<<i+1<<" ";
            }
        }
    }
cout<<"\n";
    ll q; cin>>q;
    while(q--)
    {
        ll l,r; cin>>l>>r;
        // l--; r--;
        int s = 0, e = vec.size()-1;
        int mid = s + (e-s)/2;
        bool flag = true;
        while(s<e)
        {
            // cout<<mid<<"\n";
            if(vec[mid] <= r)
            {
                if(vec[mid] > l)
                {
                    cout<<vec[mid]-1<<" "<<vec[mid]<<"\n";
                    flag = false;
                    break;
                }else{
                    s = mid+1;
                }
            }else{
                e = mid;
            }
            mid = s+(e-s)/2;
        }
        if(flag)
        {
            bool aa = true;
            if(s == e)
            {
                if(vec[s]>l && vec[s]<=r)
                {
                    cout<<vec[s]-1<<" "<<vec[s]<<"\n";
                    aa = false;
                }
            }
            if(aa)
            cout<<-1<<" "<<-1<<"\n";
        }
    }
    cout<<"\n";
}

int main() {
    FAST;
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}