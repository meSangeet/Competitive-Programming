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
#define sz(x) (ll)(x).size()
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

struct node {
    node* left,*right;
    node(){
        left = NULL;
        right = NULL;
    }
};

void insertNode(node* root, ll num) {
    node* cur = root;
    for (ll i = 31; i >= 0; i--) {
        ll bit = (num >> i) & 1;
        if(bit == 0){
        if (!cur->left) {
            cur->left = new node();
        }
        cur = cur->left;
        }else{
           if (!cur->right) {
            cur->right = new node();
        }
        cur = cur->right; 
        }
    }
}

ll helper(node* root, ll num) {
    node* cur = root;
    ll result = 0;
    for (ll i = 31; i >= 0; i--) {
        ll bit = (num >> i) & 1;
        if(bit == 0){
        if (cur->right) {
            result |= (1 << i);
            cur = cur->right;
        } else {
            cur = cur->left;
        }
        }else{
          if (cur->left) {
            result |= (1 << i);
            cur = cur->left;
        } else {
            cur = cur->right;
        }  
        }
    }
    return result;
}


void solve() {
    ll n; cin>>n; vi a(n);
    read(a);
    node* root = new node();
    ll m = 0;
    ll p = 0;

    for (ll num : a) {
        p ^= num;
        insertNode(root, p);
        m = max(m, helper(root, p));
    }
    cout<<m<<"\n";
}

int main() {
    FAST;
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}