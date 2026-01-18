// problem url: 
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vii = vector< vector<int> >;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define RFOR(i, n) for (int i = (n) - 1; i >= 0; i--)

#define fi first
#define se second

const int mod = 1e9+7;

void solve() {
    int n; cin >> n;
    
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int mx = 0, mxpref = 0;
    for (int i = 0; i < n; i++) {
        mxpref = max(mxpref, a[i]);
        mx += mxpref;
    }

    int ans = mx;
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            vi b(n);
            for (int k = 0; k < n; k++) b[k] = a[k];
            swap(b[i], b[j]);
            int x = 0, mxp = 0;
            for (int k = 0; k < n; k++) {
                mxp = max(mxp, b[k]);
                x += mxp;
            }
            ans = max(ans, x);
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