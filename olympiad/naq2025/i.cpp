// problem url: https://naq25.kattis.com/contests/naq25/problems/starguardians
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    
    vector<int> a; a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> s; s.resize(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    sort(s.begin(), s.end(), greater<int>());

    vector<int> pref(n+1, 0);
    for (int i = 1; i <= n; i++) pref[i] = pref[i-1] + s[i-1];

    double maxavg = 0;
    for (int sz = 1; sz <= n; sz++) {
        int solve = a[sz-1] + pref[sz];
        double avg = (double) solve / sz;
        maxavg = max(maxavg, avg);
    }
    cout << setprecision(12) << maxavg << '\n';
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