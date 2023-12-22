#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void calculateNextGreaterElement(vector<int> &ans, int n, vector<int> &a)
{
    int l = n-1;
    stack<pair<int,int>> temp;
    for(int i = l; i>=0; i--)
    {
        while(!temp.empty() && temp.top().first<a[i])
        {
            temp.pop();
        }
        
        if(temp.empty())
        {
            ans[i] = -1;
            temp.push({a[i],i});
        }else{
            ans[i] = temp.top().second;
            temp.push({a[i],i});
        }
    }
    return;
}

int main()
{
    // cout<<"enter number of elements in your array - ";
    int n; cin>>n;  
    vector<int> a(n);
    // cout<<"Enter array elements - ";
    for(int i = 0; i<n; i++)
    {
        cin>>a[i];
    }

    vector<int> ans(n);

    calculateNextGreaterElement(ans, n, a);
    // cout<<"ans - ";
    for(int i = 0; i<n; i++) cout<<ans[i]<<" ";
    return 0;
}