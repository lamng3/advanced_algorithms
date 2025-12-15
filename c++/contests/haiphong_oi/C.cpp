// problem url: https://codeforces.com/gym/658641/problem/C
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

void solve() {
    int m, n, S; cin >> m >> n >> S;
    vi a;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            a.push_back(x);
        }
    }
    sort(a.begin(), a.end());
    int sz = m * n;
    int L = 0, R = m*n-1;
    int ans = -1;
    while (L < R) {
        if (a[L] + a[R] > S) R--;
        else {
            ans = max(ans, a[L] + a[R]);
            L++;
        }
    }
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