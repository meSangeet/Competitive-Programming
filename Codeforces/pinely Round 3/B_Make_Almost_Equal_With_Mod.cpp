#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n; cin>>n;
    vector<ll> a(n);
    for(int i = 0; i<n; i++)
    {
        cin>>a[i];
    }

    bool mt2 = true;
    ll fact = 2;
    while(mt2)
    {
        unordered_map<int,int> m;
        for(auto x:a)
        {
            m[x%fact]++;
            if(m.size()>2)
            {
                break;
            }
        }
        if(m.size() == 2)
        {
            cout<<fact<<endl;
            return;
        }
        fact *= 2;
    }
    return;
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