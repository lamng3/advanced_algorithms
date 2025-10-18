// problem url: https://codeforces.com/problemset/problem/1914/C
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;
    vi a(n); for (int i = 0; i < n; i++) cin >> a[i];
    vi b(n); for (int i = 0; i < n; i++) cin >> b[i];

    ll best = 0, runsum = 0, runmax = 0;
    // we touch on quest i
    for (int i = 0; i < n; i++) {
        runsum += (ll) a[i];
        runmax = max(runmax, (ll) b[i]);
        int r = k - (i + 1);
        if (r < 0) continue;
        ll current = runsum + runmax * r;
        best = max(best, current);
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