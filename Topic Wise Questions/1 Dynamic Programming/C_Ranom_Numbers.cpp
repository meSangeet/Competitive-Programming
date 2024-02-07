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

unordered_map<char,int> val;
string s;
ll l;

ll recursion(int ind, char mx, bool changed, ll ans)
{
    if(ind == 0)
    {
        if(changed)
        {
            if(mx > s[0])
            {
                return ans-1;
            }else{
                return ans+val[s[ind]];
            }
        }else{
        ll temp = ans;
        vi anss(5);
        int i = 0;
        for(char a = 'A'; a <= 'E'; a++)
        {
            if(a >= mx)
            {
                temp += val[a];
                anss[i] = temp;
                temp -= val[a];
            }else{
                temp--;
                anss[i] = temp;
                temp++;
            }
        }
        return *max_element(all(anss));
        }
    }

    if(changed)
    {
        if(mx > s[ind])
        {
            ans--;
        }else{
            mx = s[ind];
            ans += val[s[ind]];
        }

        return recursion(ind-1, mx, changed, ans);
    }else{
        ll temp = ans;
        vi anss(5);
        int i = 0;
        for(char a = 'A'; a <= 'E'; a++)
        {
            if(a >= mx)
            {
                temp += val[a];
                anss[i] = recursion(ind-1, a, 1, temp);
                temp -= val[a];
            }else{
                ans--;
                anss[i] = recursion(ind-1,mx,1,ans);
                ans++;
            }
        }
        return *max_element(all(anss));
    }
}


void solve() {
    cin>>s;
    l = s.length();

    val['A'] = 1;
    val['B'] = 10;
    val['C'] = 100;
    val['D'] = 1000;
    val['E'] = 10000;

    ll ans = 0;

    cout<<recursion(l-1, 'A', 0, ans);
    cout<<endl;
}

int main() {
    FAST;
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}