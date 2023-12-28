#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int a,b,c; cin>>a>>b>>c;
    a ^= b;
    a ^= c;
    cout<<a<<endl;
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