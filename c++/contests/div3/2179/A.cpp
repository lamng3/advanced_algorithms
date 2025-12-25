// problem url: https://codeforces.com/contest/2179/problem/A
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k, x; cin >> k >> x;
    cout << k * x + 1 << '\n';
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