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

const ll INF = 2e18;
const int MOD = 1e9+7;

void solve() {
    int n; cin >> n;

    vector<pii> f(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        f[i] = make_pair(y, x);
    }
    sort(f.begin(), f.end());
    
    ll ans = 0;
    int L = 0, R = n-1;

    while (L < R) {
        ll time = (ll)f[L].fi + f[R].fi;
        ans = max(ans, time);
        int count = min(f[L].se, f[R].se);
        f[L].se -= count;
        f[R].se -= count;
        if (f[L].se == 0) L++;
        if (f[R].se == 0) R--;
    }

    cout << ans << '\n';
}

int main() {
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}