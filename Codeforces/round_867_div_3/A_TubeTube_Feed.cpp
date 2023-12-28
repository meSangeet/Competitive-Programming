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
    int q; cin>>q;
    while(q--)
    {
        ll n, t;
        cin>>n>>t;
        vector<int> a;
        for(int i = 0; i<n; i++)
        {
            int p; cin>>p;
            a.pb(p);
        }
        vector<int> b;
        for(int i = 0; i<n; i++)
        {
            int p; cin>>p;
            b.pb(p);
        }
        int ind = 0, msf = 0, i = 0, asf = -1;
        while(t>0 && i<n)
        {
            if(a[i] <= t)
            {
                if(b[i] > msf){
                    msf = b[i];
                    asf = i+1;
                }
            }
            i++;
            t--;
        }
        cout<<asf<<endl;

    }
}
int main()
{
    solve();
    return 0;
}