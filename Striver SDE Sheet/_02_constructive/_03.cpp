#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int r,c;
    for(int i = 1; i<=5; i++)
    {
        for(int j = 1; j<=5; j++)
        {
            int p; cin>>p;
            if(p != 0)
            {
                r = i;
                c = j;
            }
        }
    }

    int ans = abs(3-r) + abs(3-c);
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}