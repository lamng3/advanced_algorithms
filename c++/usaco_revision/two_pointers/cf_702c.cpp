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

const int MOD = 1e9+7;

bool check(const ll& r, const vi& a, const vi& b, const int& n, const int& m) {
    for (int i = 0, j = 0; i < n; i++) {
        bool ok = false;
        while (j < m) {
            ll L = -r + b[j], R = r + b[j];
            if (L <= a[i] && a[i] <= R) {
                ok = true;
                break;
            }
            j++;
        }
        if (!ok) return false;
    }
    return true;
}

ll find(const vi& a, const vi& b, const int& n, const int& m) {
    ll maxpos = 2e18;
    ll r = maxpos;
    for (ll pos = maxpos; pos > 0; pos >>= 1) {
        while (check(r - pos, a, b, n, m)) {
            r -= pos;
        }
    }
    return r;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vi b(m);
    for (int i = 0; i < m; i++) cin >> b[i];

    ll ans = find(a, b, n, m);
    cout << ans << '\n';
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