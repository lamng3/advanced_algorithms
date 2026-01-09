// problem url: https://codeforces.com/contest/2171/problem/A
#include <bits/stdc++.h>
using namespace std;

int binpw(int base, int x) {
    int r = 1;
    while (x) {
        if (x & 1) r = r * base;
        r = r * r;
        x >>= 1;
    }
    return r;
}

void solve() {
    int n; cin >> n;
    if (n % 2) {
        cout << 0 << '\n';
        return;
    }
    int r = 0;
    for (int ck = 0; ck <= n; ck += 2) {
        int cw = n - ck;
        if (cw % 4 == 0) r++;
    }
    cout << r << '\n';
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