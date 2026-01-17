// problem url: https://atcoder.jp/contests/dp/tasks/dp_o?lang=en
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vii = vector< vector<int> >;
using pii = pair< int, int >;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define RFOR(i, n) for (int i = (n) - 1; i >= 0; i--)

#define fi first
#define se second
#define pb push_back

const int mod = 1e9+7;

void solve() {
    int n; cin >> n;

    vi compat(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a; cin >> a;
            if (a) compat[i] |= (1 << j);
        }
    }

    int FULL = 1 << n;

    /*
        dp[S] = #ways to match females in subset S with the first |S| men
        dp[S] += dp[S\{w}] if last man is compatible with w
    */
    vi dp(FULL, 0);
    dp[0] = 1;

    for (int mask = 0; mask < FULL; mask++) {
        int lastman = __builtin_popcount(mask);
        for (int w = 0; w < n; w++) {
            if ((mask & (1 << w)) == 0) continue;
            if ((compat[lastman-1] & (1 << w)) == 0) continue;
            dp[mask] = (dp[mask] % mod + dp[mask ^ (1 << w)] % mod) % mod;
        }
    }
    cout << dp[FULL-1] << '\n';
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