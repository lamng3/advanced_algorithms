// problem url: https://codeforces.com/contest/1316/problem/E
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
const ll INF = 2e18;

void solve() {
    int n, p, k;
    cin >> n >> p >> k;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vii s(n, vi(p));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cin >> s[i][j];
        }
    }

    vector<pii> members(n);
    for (int i = 0; i < n; i++) members[i] = make_pair(a[i], i);
    sort(members.begin(), members.end(), greater<pii>());

    int FULL = 1 << p;

    /*
        dp[i][mask] = max score choosing |mask| from first i members
    */
    vector< vector<ll> > dp(n+1, vector<ll>(FULL, -INF));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        pii& mem = members[i-1];
        for (int mask = 0; mask < FULL; mask++) {
            // if more members selected than possible
            int players = __builtin_popcount(mask);
            if (players > i) continue;

            // if we have selected enough k audiences
            // it is better to select member right away based on the sorting
            int audiences = (i-1) - players;

            if (audiences < k) {
                // not enough audiences selected in previous state dp[i-1][mask]
                dp[i][mask] = max(dp[i][mask], dp[i-1][mask] + mem.fi);
            }
            else dp[i][mask] = max(dp[i][mask], dp[i-1][mask]);

            // select ith as player for position jth
            for (int j = 0; j < p; j++) {
                if ((mask & (1 << j)) == 0) continue;
                dp[i][mask] = max(dp[i][mask], dp[i-1][mask ^ (1 << j)] + s[mem.se][j]);
            }
        }
    }

    cout << dp[n][FULL-1] << '\n';
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