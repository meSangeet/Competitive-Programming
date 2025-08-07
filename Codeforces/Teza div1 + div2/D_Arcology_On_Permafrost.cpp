#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;
#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(v) (v).begin(), (v).end()

// GCD & LCM
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

// Modular Arithmetic
ll mod_add(ll a, ll b, ll m = MOD) { return (a % m + b % m) % m; }
ll mod_sub(ll a, ll b, ll m = MOD) { return ((a % m - b % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m = MOD) { return (a % m * b % m) % m; }
ll mod_pow(ll a, ll b, ll m = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = mod_mul(res, a, m);
        a = mod_mul(a, a, m);
        b >>= 1;
    }
    return res;
}

// Modular Inverse
ll mod_inv(ll a, ll m = MOD) { return mod_pow(a, m - 2, m); }

//to divide a number A by X mod M do   A = A*qpow(X) mod M
ll qpow(ll x, ll y, ll m = MOD - 2) {
    ll res = 1;
    while (y) {
        if (y % 2 == 1) res = res * x % m;
        x = x * x % m;
        y /= 2;
    }
    return res;
}

// Input/Output Optimization
template <typename T>
void rv(vector<T> &v) { for (auto &x : v) cin >> x; }

template <typename T>
void pv(const vector<T> &v) { for (const auto &x : v) cout << x << " "; cout << "\n"; }

// While dealing with mod make sure the final answer is not a negative number
// Read the question carefully you are literally reading questions wrong in every contest
// Make sure to read the constraints before solving the questions
// Arrive at the solution first and then start coding
// Solve Function
void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    ll s = 0, e = k - 1;
    ll c = 0;
    vector<vector<ll>> vec;
    vector<vector<ll>> rem;

    while (c < n) {
        ll no = k * (m + 1);
        if (c + no <= n) {
            vec.push_back({s, e, m + 1, -1});  // s, e, times to repeat
            s += k;
            e += k;
            c += no;
        } else {
            for (int i = 0; i <= m; i++) {
                vector<ll> temp;
                for (ll j = s; j <= e; j++) {
                    temp.push_back(j);
                    c++;
                    if (c >= n) {
                        rem.push_back(temp);
                        goto done_collecting;
                    }
                }
                rem.push_back(temp);
            }
        }
    }

done_collecting:

    // Check vec is not empty before accessing vec[0][2]
    if (vec.empty()) {
        // Handle the special case where all elements go to `rem`
        for (auto &temp : rem) {
            for (auto val : temp) cout << val << " ";
        }
        cout << "\n";
        return;
    }

    ll ind = 0;
    ll num = 0;
    while (num <= m) {
        for (auto &x : vec) {
            for (ll q = x[0]; q <= x[1]; q++) {
                cout << q << " ";
            }
        }
        num++;
        if (ind < rem.size()) {
            for (auto val : rem[ind]) {
                cout << val << " ";
            }
            ind++;
        }
    }

    cout << "\n";
}

// Main Function
int main() {
    #ifndef ONLINE_JUDGE
    freopen("Debug.txt", "w", stderr);
    #endif

    fast_io();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}