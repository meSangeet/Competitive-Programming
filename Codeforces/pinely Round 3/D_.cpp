#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=2e6+5;
long long a[N];
 
long long  gcd(long long  a, long long  b)
{
    return b ? gcd(b, a % b) : a;
}
 
void solve()
{
    long long n,i,k,aa=1,res=0,flag=0,j,s=0,ggcd,pr=-1,p,Max=0;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(i&&a[i]!=a[i-1])
            flag=1;
    }
    if(flag==0)
    {
        cout<<0<<endl;
        return ;
    }
    for(i=0;i<n;i++)
    {
        if(i&&a[i-1]>k&&a[i]<k)
        {
            cout<<-1<<endl;
            return ;
        }
        if(i&&a[i-1]<k&&a[i]>k)
        {
            cout<<-1<<endl;
            return ;
        }
        if(i)
            ggcd=gcd(ggcd,abs(a[i]-k));
        else
            ggcd=abs(a[i]-k);
    }
 
    for(i=0;i<n;i++)
    {
        res+=abs((a[i]-k))/ggcd-1;
        if((a[i]-k)/ggcd==0)
        {
            cout<<-1<<endl;
            return ;
        }
    }
    cout<<res<<endl;
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