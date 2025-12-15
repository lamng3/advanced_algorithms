// problem url: https://codeforces.com/gym/658641/problem/A
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    string r = "";
    int x = 0;
    for (int i = 0; i < s.size(); i++) {
        if ('0' <= s[i] && s[i] <= '9') x += (s[i] - '0');
        else r.insert(0, 1, s[i]);
    }
    if (r == "") r = "-1";
    cout << x << '\n';
    cout << r << '\n';
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