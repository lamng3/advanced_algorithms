// problem url: https://atcoder.jp/contests/abc187/tasks/abc187_f
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
const int INF = 1e+7;

void solve() {
    int n, m; 
    cin >> n >> m;
    
    vi g(n, 0);
    for (int i = 0; i < m; i++) {
        int a, b; 
        cin >> a >> b;
        a--; b--;
        g[a] |= (1 << b);
        g[b] |= (1 << a);
    }

    int FULL = 1 << n;
    vi dp(FULL, INF);
    
    for (int mask = 0; mask < FULL; mask++) {
        bool connected = true;
        for (int u = 0; u < n; u++) {
            if ((mask & (1 << u)) == 0) continue;
            // check if u connected to others
            for (int v = 0; v < n; v++) {
                if (u == v || (mask & (1 << v)) == 0) continue;
                if ((g[u] & (1 << v)) == 0) {
                    connected = false;
                    break;
                }
            }
        }
        if (connected) dp[mask] = 1;
    }

    for (int mask = 0; mask < FULL; mask++) {
        if (dp[mask] == 1) continue;
        for (int submask = mask; submask != 0; submask = (submask-1)&mask) {
            int subset = mask ^ submask;
            if (dp[subset] != INF && dp[submask] != INF) {
                dp[mask] = min(dp[mask], dp[subset] + dp[submask]);
            }
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