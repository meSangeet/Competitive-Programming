#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n,k,l,c,d,p,nl,np; cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    c *= d;
    // l -= n;
    if(k < n)
    {
        cout<<0<<"\n";
        return;
    }
    k *= l;
    int drink = k/nl;
    int lime = c;
    int salt = p/np;

    int ans = min({drink,lime,salt});
    ans /= n;
    
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}