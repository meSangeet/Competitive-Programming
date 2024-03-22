#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int minHammingDistance(string s, string t) {
    int n = s.size();
    int ans = n; // Initialize ans to the maximum possible value

    // For each possible mode character (0 or 1)
    for(char mode : {'0', '1'}) {
        int cnt = 0; // Count the number of differences between t and the current mode string
        for(int i = 0; i < n; i++) {
            // Check if the character at index i in t is not the mode character
            if(t[i] != mode) {
                cnt++;
            }
        }
        ans = min(ans, cnt); // Update the answer with the minimum difference found so far
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string s, t;
        cin >> s >> t;

        cout << minHammingDistance(s, t) << endl;
    }

    return 0;
}
