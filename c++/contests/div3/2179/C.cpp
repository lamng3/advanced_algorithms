// problem url: https://codeforces.com/contest/2179/problem/C
#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n; cin >> n;

    set<int> a; 
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.insert(x);
    }

    // x can be anything >= k
    // k > a[1] not possible
    // a[0] <= k <= a[1]
    // k = a[0] is guaranteed
    // k > a[0] <-> a[1] >= a[0] + k
    //     a[0] + 1 <= k <= a[1] - a[0]
    auto it = a.begin();
    int ans = *it;
    if (a.size() > 1) {
        int a0 = *it;
        // if a0 is chosen to be remainder, make sure ai % (ai - a0) != 0
        bool ok = true;
        for (int x : a) {
            if (x == a0) continue;
            if (x % (x - a0) == 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            int a1 = *next(it);
            if (a1 - a0 > a0) ans = max(ans, max(a0 + 1, a1 - a0));
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
    cin >> tt;
    while (tt--) solve();
    return 0;
}