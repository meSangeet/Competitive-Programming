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
    vector<ll> a(n+1), b(n+1), p1(n+1), p2(n+1);
    for(int i = 0; i < n; i++){
        cin>>a[i+1];
        p1[a[i+1]] = i+1;
    }
    for(int j = 0; j<n; j++){
        cin>>b[j+1];
        p2[b[j+1]] = j+1;
    }
    bool flag = false;
    int s = 1, e = n;
    vector<pair<ll,ll>> ans;
    while(s <= n){
        // cout<<"s - "<<s<<" e-"<<e<<endl;
        if(a[s] == b[s]){
            if((n%2 == 0 or flag) and s != (n+1)/2){
                cout<<-1<<endl;
                return;
            }
            if(s == (n+1)/2){
                s++;
                e--;
                continue;
            }
            flag = true;
            //now this element will go in the middle
            ll mi = (n+1)/2;
            p1[a[mi]] = s;
            p2[b[mi]] = s;
            p1[a[s]] = mi;
            p2[b[s]] = mi;
            swap(a[mi], a[s]);
            swap(b[mi], b[s]);
            ans.push_back({mi, s});
            // cout<<mi<<" "<<s<<endl;
            // for(auto x : a) cout<<x<<" ";
            // cout<<endl;
            // for(auto x : b) cout<<x<<" ";
            // cout<<endl;
        }

        if(a[s] == b[e]){
            s++;
            e--;
            continue;
        }

        //e index will be swaped by the position which contains a[s]
        ll pos = p2[a[s]];

        //if this position is later than e or earlier than s 
        if(pos > e or pos < s){
            cout<<-1<<endl;
            return;
        }

        p1[a[pos]] = e;
        p1[a[e]] = pos;
        swap(a[e], a[pos]);
        p2[b[pos]] = e;
        p2[b[e]] = pos;
        swap(b[e], b[pos]);
        ans.push_back({e, pos});
        // cout<<e<<" "<<pos<<endl;
        // for(auto x : a) cout<<x<<" ";
        //     cout<<endl;
        //     for(auto x : b) cout<<x<<" ";
        //     cout<<endl;
        s++;
        e--;
    }
    s = 1, e = n;

    if(ans.size() > n){
        cout<<-1<<endl;
        return;
    }
    while(s <= n){
        if(a[s] != b[e]){
            cout<<-1<<endl;
            return;
        }
        s++;
        e--;
    }


    cout<<ans.size()<<endl;
    for(auto x : ans){
        cout<<x.first<<" "<<x.second<<endl;
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