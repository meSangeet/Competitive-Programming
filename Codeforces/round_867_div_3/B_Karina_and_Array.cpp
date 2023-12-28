#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898
#define pb push_back

ll mult(ll a, ll b, ll p = mod)
{
    return ((a % p) * (b % p)) % p;
}
ll add(ll a, ll b, ll p = mod)
{
    return ((a % p) + (b % p)) % p;
}
ll neg(ll a, ll p = mod)
{
    return (p - (a % p)) % p;
}
ll sub(ll a, ll b, ll p = mod)
{
    return add(a, neg(b));
}
ll fpow(ll x, ll y)
{
    ll res = 1;
    x = x % mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1ll)
            res = (res * x) % mod;
        y = y >> 1ll;
        x = (x * x) % mod;
    }
    return res;
}
ll inv(ll a, ll p = mod) { return fpow(a, p - 2); }

void solve()
{
    int t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        vector<ll> a,b;
        for(ll i = 0; i<n; i++)
        {
            ll p; cin>>p;
            if(p > 0)
            a.pb(p);
            else b.pb(p);
        }
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end());
        ll an1 = INT_MIN, an2 = INT_MIN;
        if(a.size()>1)
        {
            an1 = a[0]*a[1];
        }
        if(b.size()>1)
        {
            an2 = b[0]*b[1];
        }
        if(a.size() == 1 && b.size()==1)
        {
            cout<<a[0]*b[0]<<endl;
        }else{
            cout<<max(an1,an2)<<endl;
        }
    }
}
int main()
{
    solve();
    return 0;
}