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
        int n, l;
        cin >> n >> l;

        vector<pair<int, int>> messages(n);
        for (int i = 0; i < n; i++) {
            cin >> messages[i].first >> messages[i].second;
        }

        sort(messages.begin(), messages.end());

        vector<int> prefix_sum_a(n);
        prefix_sum_a[0] = messages[0].first;
        for (int i = 1; i < n; i++) {
            prefix_sum_a[i] = prefix_sum_a[i - 1] + messages[i].first;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int j = i, total_time = 0, count = 0;
            while (j < n && total_time <= l) {
                total_time += messages[j].first;
                if (j > i) {
                    total_time += abs(messages[j].second - messages[j - 1].second);
                }
                if (total_time <= l) {
                    count++;
                    ans = max(ans, count);
                }
                j++;
            }
        }

        cout << ans << "\n";
}

int main() {
    FAST;
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}