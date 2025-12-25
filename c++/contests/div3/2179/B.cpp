// problem url: https://codeforces.com/contest/2179/problem/B
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

void solve() {
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    // d[i] = abs(a[i] - a[i-1])
    vi d(n, 0);
    int S = 0;
    for (int i = 1; i < n; i++) {
        d[i] = abs(a[i] - a[i-1]);
        S += d[i];
    }
    int best = S;
    for (int i = 0; i < n; i++) {
        // remove a[i]
        // S - abs(a[i] - a[i-1]) - abs(a[i+1] - a[i]) + abs(a[i+1] - a[i-1])
        int curr = S - d[i];
        if (i < n-1) curr -= d[i+1];
        if (i > 0 && i < n-1) curr += abs(a[i+1] - a[i-1]);
        best = min(best, curr);
    }
    cout << best << '\n';
}

int main() {
    // freopen("name.in", "r", stdin);
    // freopen("name.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
    return 0;
}