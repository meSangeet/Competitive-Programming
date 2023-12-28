#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n; cin>>n;
    cout<<1ll*(n*(n+2) + 2*1ll)<<endl;
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