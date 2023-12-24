#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n; cin>>n;
    vector<int> l(n);
    set<int> r;
    vector<int> c(n);
    for(int i = 0; i<n; i++)
    {
        cin>>l[i];
    }
    for(int i = 0; i<n; i++)
    {
        int p;  cin>>p;
        r.insert(p);
    }
    for(int i = 0; i<n; i++)
    {
        cin>>c[i];
    }
    sort(l.begin(), l.end());
    sort(c.begin(),c.end(), greater<int>());

    ll sum = 0;
    vector<int> diff(n);
    for(int i = n-1; i>=0; i--)
    {
        // sum += c[i]*(r[i]-l[i]);
        auto it = r.upper_bound(l[i]);
        diff[i] = ((*it)-l[i]);
        r.erase(it);
    }

    sort(diff.begin(),diff.end());

    for(int i = 0; i<n; i++)
    {
        sum += (1ll*c[i])*diff[i];
    }

    cout<<sum<<"\n";
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