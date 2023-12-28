#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n; cin>>n;
    ll ans = 0;
    map<int,int> m;
    vector<int> a(n);
    for(int i = 0; i<n; i++)
    {
        cin>>a[i];
        if(a[i] == 1)
        {
            ans += m[1] + m[2];
        }else
        if(a[i] == 2)
        {
            ans += m[2] + m[1];
        }else{
            ans += m[a[i]];
        }
        m[a[i]]++;
    }

    cout<<ans<<"\n";
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