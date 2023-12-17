#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n; cin>>n;
    string s; cin>>s;
    bool flag = true;
    for(int p = 0; p<s.length()-1; p++)
    {
        if(s[p] > s[p+1])
        {
            flag = false;
            break;
        }
    }
    if(flag)
    {
        cout<<0<<endl;
        return;
    }
    deque<pair<char,int>> post;
    post.push_back({s[n-1],n-1});
    pair<char,int> mm = post[0];
    for(int i = n-2; i>=0; i--)
    {
        if(s[i] >= mm.first)
        {
            post.push_front({s[i], i});
            mm = post[0];
        }
    }

    int i = 0, j = post.size()-1;
    while(i < j)
    {
        swap(s[post[i].second],s[post[j].second]);
        // cout<<i<<" "<<j<<endl;
        i++;
        j--;
    }
    for(int p = 0; p<s.length()-1; p++)
    {
        if(s[p] > s[p+1])
        {
            cout<<-1<<"\n";
            return;
        }
    }
    int count = 0;
    if(post.size()>1)
    {
        if(post[0].first == post[1].first)
        {
            char q = post[0].first;
            for(auto x:post)
            {
                if(x.first == q)
                {
                    count++;
                }
            }
        }
    }
    if(count>1)
    {
        count--;
    }
    cout<<post.size()-1-count<<endl;
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