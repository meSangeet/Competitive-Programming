#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
   ll n; cin>>n;
   
   deque<char> ans;
   while(n)
   {
    int p = n%10;
    p = min(p, 9-p);
    ans.push_front('0'+p);
    n/=10;
   }
   bool flag = false;
//    for(int i = 0; i<ans.size(); i++)
//    {
//     if(ans[i] != '0')
//     {
//         flag = true;
//     }
//    }

//    if(!flag)
//    {
//     cout<<9<<endl;
//     return;
//    }

//    int j = 0;
//    while(ans[j] == '0') ans.pop_front();
    (ans[0] == '0') ? ans[0] = '9' : ans[0] = ans[0];
   for(int i = 0; i<ans.size(); i++) cout<<ans[i];
   cout<<"\n";
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