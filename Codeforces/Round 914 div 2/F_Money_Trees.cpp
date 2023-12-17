#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n,k; cin>>n>>k;
    vector<ll> a(n);
    vector<ll> h(n);
    ll pree = 0;
    vector<ll> pre(n);
    for(int i = 0; i<n; i++)
    {
        cin>>a[i];
        pre[i] = pree+a[i];
        pree = pre[i];
    }
    for(int i = 0; i<n; i++)
    {
        cin>>h[i];
    }

    vector<ll> no;
    for(int i = 0; i<n-1; i++)
    {
        if(h[i]%h[i+1] != 0)
        {
            no.push_back(i);
        }
    }

    ll ans = 0;

    for(int i = 0; i<no.size(); i++)
    {
        if(i == 0)
        {
            ll s = pre[no[0]];
            if(s <= k)
            {
                ans = max(no[i]+1ll, ans);
            }
        }else{
            ll s = pre[no[i]] - pre[no[i-1]];
            if(s <= k)
            {
                ll l = no[i] - no[i-1];
                ans = max(ans, l);
            }
        }
    }
    ll l;
    ll s = pre[n-1] - pre[no.size()-1];
    if(no.size())
    l = n-1 - no.back();
    else l = n;
    if(s <= k)
            {
                // ll l = no[i] - no[i-1];
                ans = max(ans, l);
            }

    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}