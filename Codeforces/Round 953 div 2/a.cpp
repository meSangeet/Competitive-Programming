#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n; cin>>n;
    map<double, ll> s;
    ll count = 0;
    for(int i = 0; i<n; i++)
    {
        double p,q; cin>>p>>q;
        if(p == 0 && q == 0)
        {
            cout<<1<<endl;
            return 0;
        }
            double x = q/p;
            s[x]++;
            if(s[x] == 1)
            {
                count++;
            }
    }
    cout<<count<<endl;
    return 0;
}