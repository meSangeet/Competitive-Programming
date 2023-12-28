#include <bits/stdc++.h>

using namespace std;
#define ll long long 

bool canBuildSquare(vector<ll>& buckets) {
    ll totalSquares = 0;
    for (ll squares : buckets) {
        totalSquares += squares;
    }
    ll side = sqrt(totalSquares);
    return side * side == totalSquares;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        vector<ll> buckets(n);

        for (int i = 0; i < n; ++i) {
            cin >> buckets[i];
        }

        if (canBuildSquare(buckets)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
