#include<bits/stdc++.h>
using namespace std;
#define ll long long


bool check(int n)
{
    if(n == 1) return false;
    for(int i = 2; i*i<=n; i++)
    {
        if(n%i == 0)
        {
            return false;
        }
    }

    return true;
}

void solve()
{
    vector<int> ans;
    int a,b; cin>>a>>b;
    for(int i = a; i<=b; i++)
    {
        if(check(i))
        {
            ans.push_back(i);
        }
    }

    for(int i = 0; i<ans.size(); i++)
    {
        cout<<ans[i]<<"\n";
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