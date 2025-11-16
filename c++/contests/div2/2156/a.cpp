// problem url: 
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int h = 0;
    while (n >= 3) {
        int r = n % 3, d = n / 3;
        h += d;
        n = d + r;
    }
    cout << h << '\n';
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