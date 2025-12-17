// problem url: https://codeforces.com/contest/1062/problem/A
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

void solve() {
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0, prev = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i-1] + 1) continue;
        int d = i - prev - (a[prev] == 1 ? 1 : 2);
        ans = max(ans, d);
        prev = i;
    }
    int d = n - prev - ((a[n-1] == 1000 || a[prev] == 1) ? 1 : 2);
    ans = max(ans, d);
    cout << ans << '\n';
}

int main() {
    // freopen("name.in", "r", stdin);
    // freopen("name.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}