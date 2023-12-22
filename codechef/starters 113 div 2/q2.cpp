#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n,z=0,o=0; cin>>n;
    vector<ll> a(n);
    for(int i = 0; i<n; i++)
    {
        cin>>a[i];
        if(a[i] == 0) z++;
        else o++;
    }

    cout<<min(z,o)<<endl;
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