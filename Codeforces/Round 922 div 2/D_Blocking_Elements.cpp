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

ll func(int ind, int last, vi& a, vi& p)
{
    if (ind == a.size()) {
        // Base case: reached the beginning of the array
        return 0;
    }
    ll cost1;
    // Case 1: Block the current element
    if(last != -1 && ind != 0)
    cost1 = p[ind] - p[last]  + func(ind + 1, ind, a, p);
    else{
        cost1 = p[ind] + func(ind + 1, ind, a, p);
    }
    // Case 2: Do not block the current element
    ll cost2 = func(ind + 1, last, a, p);

    // Return the minimum cost between the two cases
    return min(cost1, cost2);
}

void solve() {
    ll n; cin>>n;
    vi a(n+1); vi p(n+1,0);
    rep(i,0,n)
    {
        cin >> a[i];
        p[i] = a[i] + p[i-1];
    }

    ll s = 0, e = p[n-1];

    ll ans = e;
    ll mid = s + (e-s)/2;

    while(s < e)
    {
        ll ss = 0;
        ll curr = 0;
        for(int i = 0; i<n; i++)
        {
            curr += a[i];
            if(curr > mid)
            {
                ss += a[i];
                curr = 0;
            }
        }

            if(curr <= mid)
            {
                ans = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }

            mid = s + (e-s)/2;
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