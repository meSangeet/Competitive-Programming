//we will check whether a number is prime or not

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

bool check(ll n)
{
    int i = 2;
    while(i*i <= n)
    {
        if(n%i == 0)
        {
            return false;
        }
        i++;
    }

    return true;
}


int main()
{
    int t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        if(check(n))
        {
            cout<<"YES"<<endl;
        }else{
            cout<<"NO\n";
        }
    }
}