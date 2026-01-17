// problem url: https://atcoder.jp/contests/dp/tasks/dp_u
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

    vii g(n, vi(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    int FULL = 1 << n;

    /* 
        dp[S] = max score of subset S
    */
    vector<ll> dp(FULL, 0);

    // prefill
    for (int mask = 0; mask < FULL; mask++) {
        ll score = 0;
        for (int u = 0; u < n; u++) {
            if ((mask & (1 << u)) == 0) continue;
            for (int v = u+1; v < n; v++) {
                if (u == v || (mask & (1 << v)) == 0) continue;
                score += g[u][v];
            }
        }
        dp[mask] = score;
    }

    for (int mask = 0; mask < FULL; mask++) {
        for (int submask = mask; submask != 0; submask = (submask-1) & mask) {
            int subset = submask ^ mask;
            dp[mask] = max(dp[mask], dp[subset] + dp[submask]);
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