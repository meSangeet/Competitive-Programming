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

vector<vector<vector<int>>> memo;
vector<vector<vector<bool>>> possible;
ll X, Y;

const int MAX_BITS = 62;

int dp(int pos, int c1, int c2) {
    if (pos == MAX_BITS) {
        // Make sure we don't have carry 1 in both x+k and y+k
        if (c1 == 1 && c2 == 1) {
            possible[pos][c1][c2] = false;
            return -2; // Invalid state
        }
        possible[pos][c1][c2] = true;
        return 0; 
    }
    
    if (memo[pos][c1][c2] != -1) {
        return memo[pos][c1][c2];
    }
    
    // Extract current bit of x and y
    int bx = (X >> pos) & 1;
    int by = (Y >> pos) & 1;
    
    int s1_0 = bx + 0 + c1; 
    int s2_0 = by + 0 + c2; 
    
    int A_bit_0 = s1_0 & 1; 
    int B_bit_0 = s2_0 & 1;  
    
    int nc1_0 = s1_0 >> 1;
    int nc2_0 = s2_0 >> 1;
    
    if (!(A_bit_0 == 1 && B_bit_0 == 1)) {
        int next_result = dp(pos + 1, nc1_0, nc2_0);
        if (next_result != -2) {  
            possible[pos][c1][c2] = true;
            memo[pos][c1][c2] = 0;  
            return 0;
        }
    }
    int s1_1 = bx + 1 + c1;  
    int s2_1 = by + 1 + c2; 
    int A_bit_1 = s1_1 & 1;  
    int B_bit_1 = s2_1 & 1;  
    
    int nc1_1 = s1_1 >> 1;
    int nc2_1 = s2_1 >> 1;

    if (!(A_bit_1 == 1 && B_bit_1 == 1)) {
        int next_result = dp(pos + 1, nc1_1, nc2_1);
        if (next_result != -2) {  
            possible[pos][c1][c2] = true;
            memo[pos][c1][c2] = 1; 
            return 1;
        }
    }
    possible[pos][c1][c2] = false;
    memo[pos][c1][c2] = -2; 
    return -2;
}

ll reconstruct_k() {
    ll k = 0;
    int c1 = 0, c2 = 0;  
    
    for (int pos = 0; pos < MAX_BITS; pos++) {
        int bit_val = memo[pos][c1][c2];
        
        if (bit_val == -2) return -1;
        
        if (bit_val == 1) {
            k |= (1LL << pos);
        }
        
        int bx = (X >> pos) & 1;
        int by = (Y >> pos) & 1;
        
        int s1 = bx + bit_val + c1;
        int s2 = by + bit_val + c2;
        
        c1 = s1 >> 1;
        c2 = s2 >> 1;
    }
    
    return k;
}

// Solve Function
void solve() {
    cin >> X >> Y;
    
    if (X == Y) {
        cout << "-1\n";
        return;
    }
    
    if ((X + Y) == (X ^ Y)) {
        cout << "0\n";
        return;
    }

    memo.assign(MAX_BITS + 1, vector<vector<int>>(2, vector<int>(2, -1)));
    possible.assign(MAX_BITS + 1, vector<vector<bool>>(2, vector<bool>(2, false)));
    
    dp(0, 0, 0);
    
    ll k = reconstruct_k();
    
    if (k > 1e18 or k == -1) {
        cout << "-1\n";
    } else {
        cout << k << "\n";
    }
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