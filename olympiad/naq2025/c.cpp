// problem url: https://naq25.kattis.com/contests/naq25/problems/callforproblemsround2
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    unordered_set<int> unique;
    for (int i = 0; i < n; i++) {
        int d; cin >> d;
        unique.insert(d);
    }
    int ans = min(k, (int) unique.size());
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