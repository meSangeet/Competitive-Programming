#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n; cin>>n;
    bool f1 = false, f2 = false, f3 = false, f4 = false;
    for(int i = 0; i<n; i++)
    {
        int p,q; cin>>p>>q;
        if(p > 0) f1 = true;
        if(p < 0) f2 = true;
        if(q > 0) f3 = true;
        if(q < 0) f4 = true;
    }

    if(f1 && f2 && f3 && f4) 
    {
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";

    
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