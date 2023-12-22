#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll x,y; cin>>x>>y;
    if(x>y)
    {
        ll ans = (x/(y+1))+(x%(y+1));
        ans = max(ans, x - 2*y);
        cout<<ans<<endl;
        return;
    }else if(x == y){
       cout<<1<<endl;
    }else{
        cout<<x<<endl;
    }
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