#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pub push_back
#define pob pop_back
#define pof pop_front
#define puf push_front
#define mp make_pair
#define vi vector<ll>
#define vp vector<pair<ll,ll>>
#define vii vector<vi>
#define vd vector<ld>
#define vb vector<bool>
#define pll pair<ll,ll>
#define maxint 2147483647
#define minint -2147483648
#define endl '\n'
#define rep(x,start,end) for(ll x = start; x < end; x++)
#define rrep(x,start,end) for(ll x = start; x >= end; x--)
#define read(x) rep(i, 0, x.size()) cin >> x[i]
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define py cout << "YES" << endl
#define pn cout << "NO" << endl
#define pyn(x) if(x) py; else pn
#define coe(x) ll odd = 0, even = 0; rep(i, 0, x.size()) {if(x[i] % 2 == 0) even++; else odd++;}
#define c01(x) ll zero = 0, one = 0; rep(i, 0, x.size()) {if(x[i] == 0) zero++; else one++;}
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define F first
#define S second
using namespace std;

ll mod1 = 1e9 + 7, mod2 = 998244353;

template<typename T> void p(T t, bool newln = true){
    cout << t;
    if(newln) cout << endl;
    else cout << " ";
}

template<typename T> void p(vector<T> t){
    rep(i, 0, sz(t)) p(t[i], false);
    cout << endl;
}

template<typename T, typename U> void p(pair<T, U> t){
    p(t.F, false);
    p(t.S);
}

int cbs(string s)
{
    // string s; cin>>s;
    ll c1 = 0, c2 = 0, c3 = 0;
    int sz = s.length();
    stack<char> st;

    for(int i = 0; i<sz; i++)
    {
        if(s[i] == '(') {c1++;
        st.push('C');
        }
        else {c2++;
        if(st.empty())
        {
            c3++;
        }else{
            st.pop();
        }
        }
    }
    c3 += st.size();
    int ans = 0; 
    if(c3>1)
    {
        return 0;
    }
    if(c2 > c1)
    {
        ll cnt = 0;
        int ind = -1;
        for(int i = 0; i<sz; i++)
        {
            if(s[i] == ')')
            {
                cnt--;
                if(cnt < 0)
                {
                    ind = i;
                    break;
                }
            }else{
                cnt++;
            }
        }
        if(ind != -1)
        ans += ind+1;
    }else{
        ll cnt = 0;
        int ind = -1;
        for(int i = sz-1; i>=0; i--)
        {
            if(s[i] == '(')
            {
                cnt--;
                if(cnt < 0)
                {
                    ind = i;
                    break;
                }
            }else{
                cnt++;
            }
        }
        if(ind != -1)
        ans += sz-ind;
    }
    return ans;
}

void solve() {
    string s; cin>>s;
    cout<<cbs(s)<<endl;
    // ll c1 = 0, c2 = 0;
    // int sz = s.length();
    // for(int i = 0; i<sz; i++)
    // {
    //     if(s[i] == '(') c1++;
    //     else c2++;
    // }
    // int ans = 0;
    // if(abs(c1-c2)>1)
    // {
    //     cout<<0<<endl;
    //     return;
    // }
    // if(c2 > c1)
    // {
    //     ll cnt = 0;
    //     int ind;
    //     int cc = 0;
    //     for(int i = 0; i<sz; i++)
    //     {
    //         if(s[i] == ')')
    //         {
    //             cnt--;
    //             if(cnt < 0)
    //             {
    //                 ind = i;
    //                 break;
    //             }
    //         }else{
    //             cnt++;
    //         }
    //         cc++;
    //     }
    //     ans += ind+1;
    // }else{
    //     ll cnt = 0;
    //     int ind;
    //     int cc = 0;
    //     for(int i = sz-1; i>=0; i--)
    //     {
    //         if(s[i] == '(')
    //         {
    //             cnt--;
    //             if(cnt < 0)
    //             {
    //                 ind = i;
    //                 break;
    //             }
    //         }else{
    //             cnt++;
    //         }
    //             cc++;
    //     }
    //     ans += ind+1;
    // }
    // p(ans);
}

int main() {
    FAST;
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}