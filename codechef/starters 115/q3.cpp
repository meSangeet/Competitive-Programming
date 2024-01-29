#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n; cin>>n;
    ll x; cin>>x;
    if(x == 0)
    {
        for(int i = 1; i<=n; i++) cout<<i<<" ";
        cout<<"\n";
        return;
    }
    if(x >= n-1)
    {
        cout<<-1<<"\n";
        return;
    }
    int i = 1;
    int last = x;
    cout<<n<<" ";
    for(int i = 1; i<=x; i++)
    {
        cout<<i<<" ";
    }

    for(int i = n-1; i>x; i--)
    {
        cout<<i<<" ";
    }

    cout<<"\n";

}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}