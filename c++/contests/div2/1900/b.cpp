// problem url: https://codeforces.com/contest/1900/problem/B
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c; cin >> a >> b >> c;
    int x = 1 - abs(b-c) % 2;
    int y = 1 - abs(c-a) % 2;    
    int z = 1 - abs(a-b) % 2;    
    cout << x << ' ' << y << ' ' << z << '\n';
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