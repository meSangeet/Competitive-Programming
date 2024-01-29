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



void solve() {
    int h, w, xa, ya, xb, yb;
        cin >> h >> w >> ya >> xa >> yb >> xb;

        int rd = yb - ya;
        int cd = abs(xa - xb);
        if(rd <= 0)
        {
            cout<<"Draw\n";
            return;
        }

        if(rd%2)
        {
            if(cd == 0)
            {
                cout<<"Alice\n";
                return;
            }
                int al = rd/2 + 1;
                int bo = rd / 2;
            if(xa > xb)
            {

                int aal = max(1, xa-al);
                int boo = max(1, xb-bo);
                if(boo < aal)
                {
                    cout<<"Draw\n";
                    return;
                }
                cout<<"Alice\n";
                return;
            }
            int aal = min(w, xa+al);
            int boo = min(w, xb+bo);
                if(boo > aal)
                {
                    cout<<"Draw\n";
                    return;
                }
                cout<<"Alice\n";
                return;
        }else{
            if(cd == 0)
            {
                cout<<"Bob\n";
                return;
            }
            int turns = (rd/2);

            if(xa > xb)
            {
                int al = min(w, xa+turns);
                int bo = min(w, xb+turns);
                if(al > bo)
                {
                    cout<<"Draw\n";
                    return;
                }
                cout<<"Bob\n";
                return;
            }

            int al = max(1, xa-turns);
            int bo = max(1, xb-turns);
            if(al < bo)
            {
                cout<<"Draw\n";
                return;
            }

            cout<<"Bob\n";
            return;


        }
}

int main() {
    FAST;
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}