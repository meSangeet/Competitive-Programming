#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n; cin>>n;
    vector<int> a,b;
    
    for(int i = 0; i<n; i++)
    {
        int p; cin>>p;
        a.push_back(p);
    }
    for(int i = 0; i<n; i++)
    {
        int p; cin>>p;
        b.push_back(p);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if(a[0]+b[n-1] != b[0]+a[n-1])
    {
        cout<<-1<<"\n";
        return;
    }
    for(int i = 1; i<n-1; i++)
    {
        if(a[i] + b[n-i-1] != a[0] +  b[n-1])
        {
            cout<<-1<<"\n";
            return;
        }
    }
    for(int i = 0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    for(int i = n-1; i>=0; i--)
    {
        cout<<b[i]<<" ";
    }
    cout<<"\n";

}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}