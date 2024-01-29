#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<ll> a(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        while (q--) {
            int s, d, k;
            cin >> s >> d >> k;

            ll result = 0;

            // Calculate the sum using a closed-form formula
            result = (k * a[s]) + (d * (k - 1) * k / 2);

            cout << result << " ";
        }

        cout << endl;
    }

    return 0;
}
