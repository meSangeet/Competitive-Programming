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
    ll n; 
    cin >> n;
    
    ll xt = 4, yt = 4, cx = 2, cy = 2; // Initialize values correctly

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;

        if (i == 0) {
            cout << "1 1\n"; // First guest always sits at (1,1)
            continue;
        }

        if (x == 0) {  // Needs a fully empty table
            if (xt < yt) {  // Prioritize lower x
                cout << xt << " 1\n";
                if(cx == xt) cx++;
                xt += 3;  // Move to the next available empty table
            } else {
                cout << "1 " << yt << "\n";
                if(cy == yt) cy++;
                yt += 3;
            }
        } else {  // Needs a partially occupied table
            if (cx < cy) { // Prioritize smaller x
                cout << cx << " 1\n";
                if(cx == xt) xt += 3;
                cx++;
                if (cx % 3 == 0){ cx++; // Skip table positions
                if(cx <= xt) cx++; }
            } else {
                cout << "1 " << cy << "\n";
                if(cy == yt) yt += 3;
                cy++;
                if (cy % 3 == 0){ cy++; // Skip table positions
                if(cy <= yt) cy++; }
            }
        }
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