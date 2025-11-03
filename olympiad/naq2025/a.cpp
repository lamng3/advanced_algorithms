// problem url: https://naq25.kattis.com/contests/naq25/problems/artinstallation
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int r, g, b; cin >> r >> g >> b;
    int cr, cg, cb; cin >> cr >> cg >> cb;
    int crg, cgb; cin >> crg >> cgb;

    int rneed = r - cr;
    int gneed = g - cg;
    int bneed = b - cb;

    int ans = 0;

    if (rneed > crg) { cout << -1 << '\n'; return; }
    if (rneed > 0) { ans += rneed; crg -= rneed; }

    if (bneed > cgb) { cout << -1 << '\n'; return; }
    if (bneed > 0) { ans += bneed; cgb -= bneed; }
    
    int cgg = crg + cgb;
    if (gneed > cgg) { cout << -1 << '\n'; return; }
    if (gneed > 0) { ans += gneed; cgg -= gneed; }

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