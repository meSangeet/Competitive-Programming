#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n; cin>>n;
    if(n%2 == 1)
    {
        if(n == 1)
        {
            cout<<1<<endl;
            return;
        }

        cout<<-1<<endl;
        return;
    }

    vector<int> e, o;
    e.push_back(n);
    o.push_back(n-1);
    for(int i = 2; i<n; i+=2)
    {
        e.push_back(i);
    }
    for(int j = n - 3; j>=1; j-=2)
    {
        o.push_back(j);
    }

    for(int i = 0; i<e.size(); i++)
    {
        cout<<e[i]<<" "<<o[i]<<" ";
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