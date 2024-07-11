#include<bits/stdc++.h>
using namespace std;

int main()              
{                     
    string s; cin>>s;       
                            
    string a = "", b = "";     
                             
    int i = 1;                     
                                
    while(s[i] != ')')             
    {         
        a += s[i];
        i++;
    }          
                  
    i += 2;         
    char c = 'x';         
    while(s[i] != ')')           
    {                           
        b += s[i];                                               
        if(s[i] >= 'a' && s[i] <= 'z') c = s[i];         
        i++;                                     
    }                                               

    // cout<<a<<endl<<b<<endl;
    // a = b;
    map<int,int> m1;
    map<int,int> m2;

    i = 0;
    bool flag = false;
    int l1 = a.length();
    while(i<l1)
    {
        // cout<<i<<endl;
        string num = "";
        while(i<l1 && a[i] != c)
        {
            num += a[i];
            i++;
        }
        int no = stoi(num);
        if(i == l1)
        {
            m1[0] += no;
            break;
        }
        i++;
        string exp = "";
        // cout<<i<<endl;
        if(a[i] == '^'){
        i++;
        if(a[i] == '-') {exp += '-'; i++;}
        while(i<l1 && (a[i] != '+' && a[i] != '-'))
        {
            exp += a[i];
            // cout<<exp<<endl;
            i++;
        }
        }
        // cout<<exp<<endl;
        // cout<<i<<endl;
        int ex;
        if(exp == "")
        {
            ex = 1;
        }else{
            ex = stoi(exp);
        }
        
        m1[ex] += no;
        // cout<<i<<endl;
    }

    i = 0;
    flag = false;
    l1 = b.length();
    while(i<l1)
    {
        // cout<<i<<endl;
        string num = "";
        while(i<l1 && b[i] != c)
        {
            num += b[i];
            i++;
        }

        int no;

        if(num == "")
        {
            no = 1;
        }else{
            // cout<<2<<endl;
            no = stoi(num);
        }
        if(i == l1)
        {
            m2[0] += no;
            break;
        }
        i++;
        string exp = "";
        // cout<<i<<endl;
        if(b[i] == '^'){
        i++;
        if(b[i] == '-') {exp += '-'; i++;}
        while(i<l1 && (b[i] != '+' && b[i] != '-'))
        {
            exp += b[i];
            // cout<<exp<<endl;
            i++;
        }
        }
        // cout<<exp<<endl;
        // cout<<i<<endl;
        int ex;
        if(exp == "")
        {
            ex = 1;
        }else{
            ex = stoi(exp);
        }
        
        m2[ex] += no;
        // cout<<i<<endl;
    }

    map<int,int> ans;

    for(auto x:m1)
    {
        int no = x.second;
        int exp = x.first;
        for(auto y:m2)
        {
            int n = y.second;
            int e = y.first;
            n *= no;
            e += exp;
            ans[e] += n;
        }
    }
    vector<pair<int,int>> v;
    for(auto x:ans)
    {   
        // cout<<x.second<<" "<<x.first<<endl;
        v.push_back({x.second, x.first});
    }   
    reverse(v.begin(), v.end());
    for(int i = 0; i<v.size(); i++)
    {
        if(i > 0 && v[i].first > 0) cout<<'+';
        if(v[i].first != 1)
        cout<<v[i].first;
        if(v[i].second != 0)
        {
            cout<<'x';
            if(v[i].second > 1)
            {
                cout<<"^"<<v[i].second;
            }
            if(v[i].second < 0)
            {
                cout<<"^"<<v[i].second;
            }
        }
    }

    return 0;
}