#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int a,b; cin>>a>>b;
    int x1,y1; cin>>x1>>y1;
    int x2,y2; cin>>x2>>y2;

    map<pair<int,int>,int> m1;

    int p[] = {a,a,b,b,-1*a,-1*a,-1*b,-1*b};
    int q[] = {b,-1*b,a,-1*a,b,-1*b,a,-1*a};


    // cout<<"for king - "<<endl;
    for(int i = 0; i<8; i++)
    {
        int x,y;
        x = x1+p[i];
        y = y1+q[i];
        m1[{x,y}] = 1;
        // cout<<x<<" "<<y<<endl;
    }

    int ans = 0;
    // cout<<"for queen - "<<endl;
    for(int i = 0; i<8; i++)
    {
        int x,y;
        x = x2+p[i];
        y = y2+q[i];
        // cout<<x<<" "<<y<<endl;
        if(m1[{x,y}] == 1)
        {
            ans++;
            m1[{x,y}] = 2;
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