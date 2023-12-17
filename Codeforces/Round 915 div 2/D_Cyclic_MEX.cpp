#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n; cin>>n;
    vector<int> p(n);
    set<int> s;
    unordered_map<int,int> m;
    int z = 0;
    for(int i = 0; i<n; i++)
    {
        s.insert(i);
        cin>>p[i];
        if(p[i] == 0){
            z = 0;
        }
    }
    s.insert(n);
    ll ans = 0;
    for(int i = 0; i<n; i++)
    {
        int ind = (i+z)%n;
        m[p[ind]] = 1;
        int tt = *s.begin();
        while(m[tt])
        {
            s.erase(tt);
            tt = *s.begin();
        }

        ans += tt;
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