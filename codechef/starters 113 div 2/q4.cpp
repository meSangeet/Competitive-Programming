#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n,m; cin>>n>>m;
    vector<ll> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    sort(a.begin(),a.end());
    ll maxi = a[n-1], mini = a[0];
    ll totp = 0, maxp = maxi - mini;
    for(int i = 0; i<n; i++) totp += maxi - a[i];
    cout<<max((ll)ceil((1.0*totp)/m),maxp)<<endl;
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