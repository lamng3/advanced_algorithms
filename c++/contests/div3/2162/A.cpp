// problem url: https://codeforces.com/contest/2162/problem/A
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vii = vector< vector<int> >;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define RFOR(i, n) for (int i = (n) - 1; i >= 0; i--)

const int mod = 1e9+7;

void solve() {
    int n; cin >> n;

    vi a(n);
    REP(i, n) cin >> a[i];
    
    vi pref(n);
    pref[0] = a[0];
    FOR(i, 1, n-1) pref[i] = pref[i-1] + a[i];

    int ans = 0;    
    FOR(L, 0, n-1) {
        FOR(R, L, n-1) {
            int S = (pref[R] - (L > 0 ? pref[L-1] : 0)) / (R - L + 1);
            ans = max(ans, S);
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