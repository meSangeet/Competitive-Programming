#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll a, b;
    cin >> a >> b;
    ll g = __gcd(a,b);
    if( ((a * b) / g) == b ) cout<< ((b/a)*(a*b)/g) ; else cout<< (a*b)/g; // Finding the LCM
    
    cout << "\n";
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
