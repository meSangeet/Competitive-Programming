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
    ll n; cin>>n;
    vector<ll> z;
    bool f1 = false;
    bool f2 = false;
    for(int i = 0; i<n; i++){
        ll x; cin>>x;
        if(x == 0){
            if(i == 0){
                f1 = true;
            }
            if(i == n-1){
                f2 = true;
            }
            z.push_back(i+1);
        }
    }
    // cout<<"n - "<<n<<endl;
    if(z.size() == 0){
        cout<<1<<endl;
        cout<<1<<" "<<n<<endl;
        return;
    }

    if(z.size() == 1){
        ll ind = z[0];
        if(ind > 1){
            cout<<2<<endl;
            cout<<ind-1<<" "<<ind<<endl;
            cout<<1<<" "<<n-1<<endl;
            return;
        }

        if(ind == 1){
            cout<<2<<endl;
            cout<<1<<" "<<2<<endl;
            cout<<1<<" "<<n-1<<endl;
            return;
        }
    }

    if(!f1){
        cout<<2<<endl;
        cout<<2<<" "<<n<<endl;
        cout<<1<<" "<<2<<endl;
        return;
    }

    if(!f2){
        cout<<2<<endl;
        cout<<1<<" "<<n-1<<endl;
        cout<<1<<" "<<2<<endl;
        return;
    }

    cout<<3<<endl;
    cout<<1<<" "<<n-2<<endl;
    cout<<2<<" "<<3<<endl;
    cout<<1<<" "<<2<<endl;
}

// Main Function
int main() {
    #ifndef ONLINE_JUDGE
    freopen("Debug.txt", "w", stderr);
    #endif

    fast_io();
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}