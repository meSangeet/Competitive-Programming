#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n; cin>>n;
    vector<ll> a(n),b(n);
    ll miin = INT_MAX;
    int ind = -1;
    for(int i = 0; i<n; i++)
    {
        cin>>a[i];
        if(a[i] < miin)
        {
            miin = a[i];
        }
        b[i] = miin;
    }
    ll cur = 0, last = a[n-1];
    ll count = 0;
    vector<int> C(n,0);
    for(int i = n-1; i>=0; i--)
    {
        ll count1 = 0;
        if(b[i] != cur)
        {
            if(i != 0){
            count1 = b[i]-cur;
            cur = b[i];
            }else{
                count1++;
            }
        }
        
        if(a[i] > b[i])
        {
            count1++;
        }

        C[i] = count1;
    }
    
    for(int i = 0; i<n; i++){
        count += C[i];
        if(count > (i+1))
        {
            count = i+1;
        }
    }

    cout<<count<<"\n";
}

int main() {
	int t; cin>>t;
	while(t--)
	{
	    solve();
	}
	
    return 0;
}
