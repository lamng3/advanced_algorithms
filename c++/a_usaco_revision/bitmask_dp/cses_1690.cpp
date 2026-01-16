// problem url: 
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
    int n, m;
    cin >> n >> m;

    vii g(n, vi());
    for (int i = 0; i < m; i++) {
        int a, b; 
        cin >> a >> b;
        a--; b--;
        g[b].pb(a);
    }

    int FULL = 1 << n;
    vii dp(FULL, vi(n, 0));
    dp[1][0] = 1;

    for (int mask = 0; mask < FULL; mask++) {
        if ((mask & (1 << 0)) == 0) continue;
        if ((mask & (1 << (n-1))) && (mask != FULL-1)) continue;

        for (int u = 0; u < n; u++) {
            if ((mask & (1 << u)) == 0) continue;

            for (int v : g[u]) {
                // from v go to u
                if ((mask & (1 << v)) == 0) continue;
                int prev_state = mask ^ (1 << u);
                dp[mask][u] = (dp[mask][u] + dp[prev_state][v]) % mod;
            }
        }
    }

    cout << dp[FULL-1][n-1] << '\n';
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