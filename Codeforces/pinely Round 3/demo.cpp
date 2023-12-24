#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(vector<int> &A, int l, int r, long long sum, long long &count)
{
    int n = A.size();
    if(l+1 >= r) return;
    if(l >= n) return;
    if(r <= 0) return;
    //first 2
    long long s;
    if(((l+1) < n) && ((l+1)<r)){
    s = A[l]+A[l+1];
    if(s == sum) count++;
    if(s == sum)
    {
        solve(A, l+2, r, sum, count);
    }
    }

    //first and last
    s = A[l]+A[r];
    if(s == sum)
    {
        count++;
        solve(A,l+1,r-1,sum,count);
    }

    //last 2
    if((r-1 >= 0) && (l+1 < r)){
    s = A[r]+A[r-1];
    if(s == sum) count++;
    if(s == sum)
    {
        // count++;
        solve(A,l,r-2,sum,count);
    }
    }
}


int solution(vector<int> &A)
{
    int n = A.size();
    if(n < 2) return 0;
    
    ll count1 = 0, count2 = 0, count3 = 0;
    int l = 0, r = n-1;
    ll sum = A[0]+A[1];
    if(l+2 < n)
    {
        solve(A,l+2,n-1,sum,count1);
    }

    sum = A[n-1]+A[n-2];
    if(n-3 >= 0)
    {
        solve(A,l,n-3,sum,count2);
    }

    sum = A[0]+A[n-1];
    solve(A,1,n-2,sum,count3);

    ll ans = max(count1, max(count2,count3));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t = 1;
    cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<int> A(n);
        for(int i = 0; i<n; i++) cin>>A[i];
        cout<<solution(A)<<endl;
    }
    return 0;
}