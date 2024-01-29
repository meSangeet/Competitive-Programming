#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<ll> b(n);
    ll pro = 1;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        pro *= b[i];
    }

    if(2023%pro != 0)
    {
        cout<<"NO"<<"\n";
        return;
    }
    cout<<"YES"<<"\n";
    
    
    k--;
    cout<<2023/pro<<" ";
    while(k)
    {
        cout<<1<<" ";
        k--;
    }
    cout<<"\n";

}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
