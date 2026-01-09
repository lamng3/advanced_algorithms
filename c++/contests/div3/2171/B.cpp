// problem url: https://codeforces.com/contest/2171/problem/B
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // minimize abs(a[n-1] - a[0])
    if (a[0] == -1 && a[n-1] == -1) {
        a[0] = 0;
        a[n-1] = 0;
    } else if (a[0] == -1) {
        a[0] = a[n-1];
    } else if (a[n-1] == -1) {
        a[n-1] = a[0];
    }

    for (int i = 1; i < n-1; i++) {
        if (a[i] == -1) a[i] = 0;
    }

    cout << abs(a[n-1] - a[0]) << '\n';
    for (int i = 0; i < n; i++) cout << a[i] << (i == n-1 ? '\n' : ' ');
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