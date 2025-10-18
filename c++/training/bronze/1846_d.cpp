// problem url: https://codeforces.com/contest/1846/problem/D
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, d, h;
    cin >> n >> d >> h;
    vector<int> y(n);
    for (int i = 0; i < n; i++) cin >> y[i];
    sort(y.begin(), y.end());
    long double triangle = (long double) d * h / 2;
    long double area = 0;
    int bottom = -1;
    for (int i = n-1; i >= 0; i--) {
        long double overlap = 0;
        // y[i] + h > bottom and y[i] < bottom
        if (y[i] < bottom && bottom < y[i] + h) {
            long double ratio = (long double) (y[i] + h - bottom) / h;
            overlap = triangle * ratio * ratio;
        }
        area += triangle - overlap;
        bottom = y[i];
    }
    cout << fixed << setprecision(10) << area << '\n';
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