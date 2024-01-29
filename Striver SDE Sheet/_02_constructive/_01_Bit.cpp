#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n; cin>>n;
    int ans = 0;
    while(n--){
    string s;
    cin>>s;
    int p;
    char q;
    if(s[0] == '-' || s[0] == '+')
    {
        q = s[0];
        if(q == '+')
        {
            ans += 1;
        }else{
            ans -= 1;
        }
    }else{
        int l = s.length()-1;
        q = s[l];
        if(q == '+')
        {
            ans += 1;
        }else{
            ans -= 1;
        }
    }
    // cout<<ans<<endl;
    }
    cout<<ans<<"\n";
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