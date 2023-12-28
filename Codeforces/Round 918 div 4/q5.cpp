#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool canShareJuice(int n, vector<ll>& glasses) {
    unordered_map<ll, ll> prefixSums; 
    ll oddSum = 0, evenSum = 0, totsum = 0;
    prefixSums[0] = 1;

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            evenSum += glasses[i];
            totsum += glasses[i];
        } else {
            oddSum += glasses[i];
            totsum -= glasses[i];
        }

        ll diff = evenSum - oddSum;
        if(prefixSums[totsum] == 1)
        {
            return true;
        }
        prefixSums[totsum] = 1;
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<ll> glasses(n);

        for (int i = 0; i < n; ++i) {
            cin >> glasses[i];
        }

        if (canShareJuice(n, glasses)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}