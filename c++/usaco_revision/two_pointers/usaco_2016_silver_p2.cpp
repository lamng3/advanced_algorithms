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

void preprocess() {

}

void solve() {
    int n, k; cin >> n >> k;
    
    vi d(n);
    for (int i = 0; i < n; i++) cin >> d[i];
    sort(d.begin(), d.end());

    vi sz(n, 0);
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && d[j] - d[i] <= k) {
            j++;
        }
        // d[j] > d[i] + k
        // [i..j-1]
        sz[i] = j - i;
    }

    // choose 2 ranges in set of ranges that maximize count

    vi pref(n, 0);
    pref[0] = sz[0];
    for (int i = 1; i < n; i++) pref[i] = max(pref[i], sz[i]);

    vi suff(n, 0);
    suff[n-1] = sz[n-1];
    for (int i = n-2; i >= 0; i--) suff[i] = max(suff[i+1], sz[i]);

    int mx = 0;
    for (int i = 0; i < n; i++) {
        int j = i + sz[i] - 1;
        int best = j+1 < n ? suff[j+1] : 0;
        mx = max(mx, sz[i] + best);
    }
    cout << mx << '\n';
}

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    preprocess();
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}