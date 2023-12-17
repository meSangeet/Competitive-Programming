#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n, k;
    cin>>n>>k;
    vector<ll> a(n);
    for(int i = 0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    if(k >= 3)
    {
        cout<<0<<endl;
        return;
    }
    if(k == 1){
    ll miin = LLONG_MAX;
    for(int i = 0; i<n-1; i++)
    {   miin = min(a[i], miin*1ll);
        miin = min(miin, abs(a[i]-a[i+1])*1ll);
    }
    miin = min(miin, a[n-1]);
    cout<<miin<<endl;
    return;
    }
    if(k == 2){
        vector<ll> pairs;
        ll miin = LLONG_MAX;
        for(int i = 0; i<n-1; i++)
        {
            miin = min(a[i], miin);
            for(int j = i+1; j<n; j++)
            {
                miin = min(1ll*abs(a[i]-a[j]), miin);
                pairs.push_back(abs(a[i]-a[j]));
            }
        }

        for(int i = 0; i<pairs.size(); i++)
        {
            auto m = upper_bound(a.begin(),a.end(),pairs[i]);
            auto n = lower_bound(a.begin(),a.end(),pairs[i]);

            if(m != a.end()){
                miin = min(miin,abs(pairs[i]-*m));
            }

            if(*n == pairs[i])
            {
                cout<<0<<endl;
                return;
            }else{
                if(n != a.begin())
                {
                    n--;
                    miin = min(miin,abs(pairs[i]-*n));
                }
            }
        }
        cout<<miin<<endl;
        return;

    }
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