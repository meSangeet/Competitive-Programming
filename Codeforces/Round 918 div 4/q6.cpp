#include<bits/stdc++.h>
using namespace std;
#define ll long long


void merge(vector<ll>& A, vector<ll>& B, ll left, ll mid, ll right, vector<ll>& count) {
    ll i = left;
    ll j = mid + 1;
    ll k = left;
    ll inversionCount = 0;

    while (i <= mid && j <= right) {
        if (A[i] <= A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
            inversionCount += (mid - i + 1); // Count elements smaller than A[j] in left subarray
        }
    }

    while (i <= mid) {
        B[k++] = A[i++];
    }

    while (j <= right) {
        B[k++] = A[j++];
    }

    for (int i = left; i <= right; ++i) {
        A[i] = B[i];
    }

    count[right] += inversionCount; // Add inversion count to the last element of the current partition
}

void mergeSort(vector<ll>& A, vector<ll>& B, ll left, ll right, vector<ll>& count) {
    if (left < right) {
        ll mid = left + (right - left) / 2;
        mergeSort(A, B, left, mid, count);
        mergeSort(A, B, mid + 1, right, count);
        merge(A, B, left, mid, right, count);
    }
}

void solve()
{
    int n; cin>>n;
    vector<pair<ll,ll>> a;
    for(int i = 0; i<n; i++)
    {
        ll p,q; cin>>p>>q;
        a.push_back({q,p});
    }

    sort(a.begin(), a.end());

    vector<ll> A(n);
    for(int i = 0; i<n; i++)
    {
        A[i] = a[i].second;
    }

    vector<ll> B(n);
    vector<ll> count(n, 0);

    mergeSort(A, B, 0, n - 1, count);

    ll ans = 0;
    for(auto x: count)
    {
        ans += x;
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}