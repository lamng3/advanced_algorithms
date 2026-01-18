// problem url: 
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vii = vector< vector<int> >;
using pii = pair<int, int>;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define RFOR(i, n) for (int i = (n) - 1; i >= 0; i--)

#define fi first
#define se second

const int mod = 1e9+7;

void solve() {
    int n, m, h; 
    cin >> n >> m >> h;

    vector<ll> a(n);
    REP(i, n) cin >> a[i];

    vi b(m);
    vector<ll> c(m);
    REP(i, m) {
        cin >> b[i] >> c[i];
        --b[i];
    }

    // a[b[i]] + c[i]
    
    // inc[i] = total increments applied to i
    vector<ll> inc(n, 0);
    // time[i] = which epoch inc[i] belongs to
    vi time(n, 0);

    int epoch = 1;

    REP(i, m) {
        int idx = b[i];
        ll add = c[i];

        ll curinc = (time[idx] == epoch ? inc[idx] : 0);
        ll newinc = curinc + add;

        if (a[idx] + newinc > h) epoch++;
        else {
            time[idx] = epoch;
            inc[idx] = newinc;
        }
    }

    REP(i, n) {
        ll ans = a[i] + (time[i] == epoch ? inc[i] : 0);
        cout << ans << (i+1 == n ? '\n' : ' ');
    }
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