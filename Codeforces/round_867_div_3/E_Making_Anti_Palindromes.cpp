#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n; cin>>n;
    string s; cin>>s;
    unordered_map<char,ll> m;
    if(n&1)
    {
        cout<<-1<<"\n";
        return;
    }
    for(int i = 0; i<n; i++)
    {
        m[s[i]]++;
        if(m[s[i]] > (n/2))
        {
            cout<<-1<<"\n";
            return;
        }
    }
    ll count = 0;
    ll tot = 0, maxi = 0;
    int i = 0, j = (n-1);
    unordered_map<char,ll> m1;
    while(i < j)
    {
        if(s[i] == s[j]) {m1[s[i]]++, tot++;};
        maxi = max(maxi, m1[s[i]]);
        i++;
        j--;
    }


    // multiset<ll> ms;

    // for(auto x:m1)
    // {
    //     ms.insert(x.second);
    // }
    // while(ms.size())
    // {
    //     if(ms.size() == 1)
    //     {
    //         count += *(ms.begin());
    //         cout<<count<<"\n";
    //         return;
    //     }

    //     auto it1 = ms.begin();
    //     auto it2 = ms.end();
    //     it2--;

    //     int a = *it1, b = *it2;
        

    //     count += a;

    //     ms.erase(it1);
    //     ms.erase(it2);

    //     if((b-a))
    //     {
    //         ms.insert(b-a);
    //     }
    // }
    if(maxi >= (tot-maxi))
    {
        cout<<maxi<<endl;
        return;
    }

    cout<<(tot/2)+(tot%2)<<endl;
    // cout<<count<<"\n";
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