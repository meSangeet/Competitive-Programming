#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isV(char a)
{
    if(a == 'a' || a == 'e')
    {
        return true;
    }

    return false;
}
void solve()
{
    int n; cin>>n;
    string s; cin>>s;
    string ans = "";
    for(int i = 0; i<n;)
    {
        ans.push_back(s[i]);
        ans.push_back(s[i+1]);
        if(i+3 < n)
        {
            if(!isV(s[i+3]))
            {
                ans.push_back(s[i+2]);
                ans.push_back('.');
                i = i+3;
                continue;
            }else{
                ans.push_back('.');
                i = i+2;
                continue;
            }
        }else{
            if(i+2 < n)
            {
                ans.push_back(s[i+2]);
                break;
            }
            break;
        }
    }
    cout<<ans<<"\n";
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