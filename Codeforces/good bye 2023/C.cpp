#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n; cin>>n;
    vector<ll> a(n);
    ll o = 0, e = 0, os = 0, es = 0;
    for(int i = 0; i<n; i++) cin>>a[i];

    for(int i = 0; i<n; i++)
    {
        if(a[i]%2 == 0)
        {
            e++;
            es += a[i];
        }else{
            o++;
            os += a[i];
        }
        if(i == 0)
        {
            cout<<a[i]<<" ";
            continue;
        }
        if(i == 1)
        {
            cout<<((a[0]+a[1])/2)*2<<" ";
            continue;
        }
        ll p = o/3;
        ll q = o - p*3;
        ll ans =  p + q%2;
        ll oos = os - ans;
        ans = es + oos;
        cout<<ans<<" ";

    }

    cout<<"\n";
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