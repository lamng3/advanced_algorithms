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

const int INF = 1e9+7;
const int MOD = 1e9+7;

void solve() {
    int n, m;
    cin >> n >> m;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vi b(m);
    for (int i = 0; i < m; i++) cin >> b[i];

    int j;
    vi d(n, 2 * INF);

    j = 0;
    for (int i = 0; i < n; i++) {
        while (j < m-1 && b[j+1] <= a[i]) {
            j++;
        }
        d[i] = min(d[i], abs(a[i] - b[j]));
    }

    j = m-1;
    for (int i = n-1; i >= 0; i--) {
        while (j > 0 && b[j-1] >= a[i]) {
            j--;
        }
        d[i] = min(d[i], abs(a[i] - b[j]));
    }

    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, d[i]);
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