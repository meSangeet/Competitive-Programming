#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n; cin>>n;
    vector<pair<int,int>> a;
    
    for(int i = 0; i<n; i++)
    {
        int p; cin>>p;
        a.push_back({p,i});
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    
    vector<ll> ss(n,0);
    ll prev = 0;
    for(int i = n-1; i>=0; i--)
    {
        ss[i] = prev+a[i].first;
        prev = ss[i];
    }
    int ap = 0;
    vector<int> app(n,0);
    for(int i = 0; i<n-1; i++)
    {
        if(a[i].first > ss[i+1])
        {
            app[i] = 0;
            ap = 0;
        }else{
            ap++;
            app[i] = ap;
        }
    }
    vector<int> ans(n,0);

    for(int i = n-1; i>=0; i--)
    {
        int aa = 0;
        aa += n-i-1;
        int j = i;
        j--;
        if(j >= 0) aa += app[j];

        /*
        while(j >= 0 && (j+1 < n) && (a[j].first <= ss[j+1]))
        {
            aa++;
            j--;
        }
        */
        ans[i] = aa;
    }
    vector<int> fa(n);

    for(int i = 0; i<n; i++)
    {
        fa[a[i].second] = ans[i];
    }

    for(int i = 0; i<n; i++)
    {
        cout<<fa[i]<<" ";
    }

    cout<<endl;
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