#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;
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

// Fast Exponentiation
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

// Factorial Precomputation
const int MAX_N = 500000;
vector<ll> fact(MAX_N + 1), inv_fact(MAX_N + 1);

void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i <= MAX_N; i++) {
        fact[i] = mod_mul(fact[i - 1], i);
    }
    inv_fact[MAX_N] = mod_inv(fact[MAX_N]);
    for (int i = MAX_N - 1; i >= 0; i--) {
        inv_fact[i] = mod_mul(inv_fact[i + 1], i + 1);
    }
}

// Compute nCr
ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return mod_mul(fact[n], mod_mul(inv_fact[r], inv_fact[n - r]));
}
// Recursive DP Function
ll solve_recursive(int index, int even_used, int odd_used, vector<int>& c) {
    if (index == 26) return (even_used == 0 && odd_used == 0) ? 1 : 0;
    if (c[index] == 0) return solve_recursive(index + 1, even_used, odd_used, c);

    ll ways = 0;

    // Try placing this character in even positions
    if (even_used >= c[index]) {
        ways = mod_add(ways, mod_mul(nCr(even_used, c[index]), solve_recursive(index + 1, even_used - c[index], odd_used, c)));
    }

    // Try placing this character in odd positions
    if (odd_used >= c[index]) {
        ways = mod_add(ways, mod_mul(nCr(odd_used, c[index]), solve_recursive(index + 1, even_used, odd_used - c[index], c)));
    }

    return ways;
}

// Solve Function
void solve() {
    vector<int> c(26);
    int total_chars = 0;
    rv(c);
    for (int count : c) total_chars += count;

    int even_positions = (total_chars + 1) / 2;
    int odd_positions = total_chars / 2;

    cout << solve_recursive(0, even_positions, odd_positions, c) << "\n";
}

// Main Function
int main() {
    #ifndef ONLINE_JUDGE
    freopen("Debug.txt", "w", stderr);
    #endif

    fast_io();
    precompute_factorials();

    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
