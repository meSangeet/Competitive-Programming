#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n; cin>>n;
    vector<ll> a(n);
    unordered_map<ll,int> s;
    for(int i = 0; i<n; i++)
    {
        cin>>a[i];
        s[a[i]]++;
    }

    if(n == 4)
    {
        if(a[0] + a[1] == a[2] + a[3])
        {
            cout<<"NO"<<endl;
            return;
        }
        cout<<"YES"<<endl;
        return;
    }

        for(int i=0; i<n-1; i++)
        {
            if(a[i] != a[i+1])
            {
                cout<<"YES"<<endl;
                return;
            }
        }

        cout<<"NO"<<endl;

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