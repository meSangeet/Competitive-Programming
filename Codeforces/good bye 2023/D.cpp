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
#define py cout << "Yes" << endl
#define pn cout << "No" << endl
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

ll powof2(ll x){
    return 1LL << x;
}

ll C(ll n, ll r) {
    if (r > n - r) r = n - r;
    ll ans = 1;
    for (ll i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }
    return ans;
}
ll P(ll n, ll r) {
    ll ans = 1;
    for (ll i = 1; i <= r; i++) {
        ans *= n - r + i;
    }
    return ans;
}

bool isprime(ll n) {
    if (n == 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

ll fact(ll n, ll mod = mod1) {
    ll ans = 1;
    for (ll i = 1; i <= n; i++) {
        ans *= i;
        ans %= mod;
    }
    return ans;
}

vi seive(ll n) {
    vi ans(n + 1, 1);
    ans[0] = 0;
    ans[1] = 0;
    for (ll i = 2; i * i <= n; i++) {
        if (ans[i]) {
            for (ll j = i * i; j <= n; j += i) {
                ans[j] = 0;
            }
        }
    }
    return ans;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll gcd(vi a) {
    ll ans = a[0];
    rep(i, 1, a.size()) ans = gcd(ans, a[i]);
    return ans;
}

ll digits(ll n) {
    return floor(log10(n)) + 1;
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

ll pow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}

ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

bool comp(ll a,ll b){
    return a<b;
}

void precompute() {
    
}

void solve() {
    ll n;
    cin >> n;
    if (n == 1) p(1);
    else if (n == 3) {
        p(169);
        p(196);
        p(961);
    } else {
        string s = "61009";
        s += string(n - 5, '0');
        p(s);
        rrep(i, n / 2, 1) {
            ll temp = n - 2 * i - 1;
            s = "";
            s += '1';
            rep(j, 1, i) s += '0';
            s += '6';
            rep(j, 1, i) s += '0';
            s += '9';
            rep(j, 0, temp) s += '0';
            p(s);
            s = "";
            s += '9';
            rep(j, 1, i) s += '0';
            s += '6';
            rep(j, 1, i) s += '0';
            s += '1';
            rep(j, 0, temp) s += '0';
            p(s);
        }
    }
}

int main() {
    auto begin = std::chrono::high_resolution_clock::now();
    FAST;
    precompute();
    ll t = 1;
    cin >> t;
    while (t--) solve();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //cerr << "Time measured: " << elapsed.count() * 1e-6 << "ms\n";
    return 0;
}