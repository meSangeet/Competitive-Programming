#include<bits/stdc++.h>
using namespace std;
#define ll long long

char give(char a, char b)
{
    

}

void solve()
{
    vector<char> arr1(3);
    vector<char> arr2(3);
    vector<char> arr3(3);
    for(int i = 0; i<3; i++) cin>>arr1[i];
    for(int i = 0; i<3; i++) cin>>arr2[i];
    for(int i = 0; i<3; i++) cin>>arr3[i];
    bool flag = false;
    vector<int> ha1(3);
    vector<int> ha2(3);
    vector<int> ha3(3);
        for(int i = 0; i<3; i++){ 
            if(arr1[i] == '?') flag = true;
            else{
                ha1[arr1[i] - 'A'] = 1;
            }
        }

        if(flag)
        {
            for(int i = 0; i<3; i++)
            {
                if(ha1[i] == 0)
                {
                    char ans = 'A'+ i;
                    cout<<ans<<endl;
                    return;
                }
            }
        }

        for(int i = 0; i<3; i++){ 
            if(arr2[i] == '?') flag = true;
            else{
                ha2[arr2[i] - 'A'] = 1;
            }
        }

        if(flag)
        {
            for(int i = 0; i<3; i++)
            {
                if(ha2[i] == 0)
                {
                    char ans = 'A'+ i;
                    cout<<ans<<endl;
                    return;
                }
            }
        }

        for(int i = 0; i<3; i++){ 
            if(arr3[i] == '?') flag = true;
            else{
                ha3[arr3[i] - 'A'] = 1;
            }
        }

        if(flag)
        {
            for(int i = 0; i<3; i++)
            {
                if(ha3[i] == 0)
                {
                    char ans = 'A'+ i;
                    cout<<ans<<endl;
                    return;
                }
            }
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