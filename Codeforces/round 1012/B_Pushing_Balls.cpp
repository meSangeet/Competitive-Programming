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
    ll m,n; cin>>m>>n;
    vector<vector<char>> v(m, vector<char> (n));
    bool flag = true;
    for(ll i = 0; i<m; i++){
        bool cont0 = false;
        for(ll j = 0; j<n; j++){
            cin>>v[i][j];
            // cout<<v[i][j]<<" ";
        }
        // cout<<endl;
    }
    
    for(ll i = 0; i<m; i++){
        for(ll j = 0; j<n; j++){
            if(v[i][j] == '1'){
                //try left
                // cout<<i<<" "<<j<<endl;
                bool ff = true;
                for(ll k = j-1; k>=0; k--){
                    if(v[i][k] == '0'){
                        ff = false;
                        break;
                    }
                }

                if(ff) continue;
                ff = true;
                for(ll k = i-1; k>=0; k--){
                    if(v[k][j] == '0'){
                        cout<<"NO\n";
                        return;
                    }
                }
            }
        }
    }

    cout<<"YES\n";
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