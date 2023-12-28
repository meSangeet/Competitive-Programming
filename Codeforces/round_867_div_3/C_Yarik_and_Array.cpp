#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n; cin>>n;
    vector<ll> arr(n);
    deque<int> ind;
    cin>>arr[0];
    int par = abs(arr[0]%2);
    for(int i = 1; i<n; i++)
    {
        cin>>arr[i];
        if(arr[i]%2 == par)
        {
            cout<<i<<" ";
            ind.push_back(i);
        }
        par = abs(arr[i]%2);
        // cout<<par<<" ";
    }
    cout<<"\n";
    for(int i = 0; i<ind.size(); i++) cout<<ind[i]<<" ";
    cout<<endl;
    ll ans = 0;
    ll curr = 0;
    int i = 0;
    while(i < n)
    {
        if(ind.size())
        {
            while(i != ind.front())
            {
                curr += arr[i];
                ans = max(ans, curr);
                if(curr < 0)
                {
                    curr = 0;
                }
                i++;
            }

            curr = 0;
            ind.pop_front();
        }else{
            curr += arr[i];
                ans = max(ans, curr);
                if(curr < 0)
                {
                    curr = 0;
                }
            i++;
        }
    }
    cout<<endl<<i<<endl;
    if(ans == 0)
    {
        ans = *max_element(arr.begin(), arr.end());
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