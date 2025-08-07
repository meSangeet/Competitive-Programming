#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200005;
vector<bool> is_prime(MAX_N, true);
vector<int> primes;
set<int> semi_primes;
int freq[MAX_N];

void preprocess() {
    // Sieve of Eratosthenes to find primes
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAX_N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j < MAX_N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 0; i < primes.size(); i++) {
        for (int j = i; j < primes.size(); j++) {
            long long semi_prime = 1LL * primes[i] * primes[j];
            if (semi_prime >= MAX_N) break;
            semi_primes.insert(semi_prime);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    memset(freq, 0, sizeof(freq));
    long long result = 0;
    long long pp = 0;
    map<int,int> fr;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if(is_prime[a[i]]){
            result += pp - fr[a[i]];
            cout<<i<<" "<<pp<<endl;
            fr[a[i]]++;
        }
        else{
            long long sq = sqrt(a[i]);
            if(sq*sq == a[i] and is_prime[sq]){
                result += freq[sq]+1;
                cout<<i<<" "<<freq[sq]+1<<endl;;
            }
        }
        freq[a[i]]++;
    }

    cout <<endl<< result << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    preprocess(); // Precompute prime and semi-prime numbers
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
