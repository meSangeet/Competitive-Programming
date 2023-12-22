#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n; cin>>n;
    vector<pair<ll,int>> a;
    vector<pair<ll,int>> b;
    vector<pair<ll,int>> c;

    for(int i = 0; i<n; i++)
    {
        ll p;
        cin>>p;
        a.push_back({p,i});
    }

    for(int i = 0; i<n; i++)
    {
        ll p;
        cin>>p;
        b.push_back({p,i});
    }

    for(int i = 0; i<n; i++)
    {
        ll p;
        cin>>p;
        c.push_back({p,i});
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());


    unordered_map<int,int> m1;
    unordered_map<int,int> m2;
    unordered_map<int,int> m3;

    for(int i = 0; i<3; i++)
    {
        m1[a[i].second] = a[i].first;
    }

    for(int i = 0; i<3; i++)
    {
        m2[b[i].second] = b[i].first;
    }

    for(int i = 0; i<3; i++)
    {
        m3[c[i].second] = c[i].first;
    }

    ll ans = 0;

    for(auto x: m1)
    {
        for(auto y:m2)
        {
            for(auto z:m3)
            {
                ll ans1 = 0;
                if((x.first != y.first) && (y.first != z.first) && (x.first != z.first))
                {
                    ll ans1 = x.second + y.second + z.second;
                    ans = max(ans, ans1);
                }
            }
        }
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