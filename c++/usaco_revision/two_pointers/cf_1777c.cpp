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

void print(map<int,int>& a) {
    for (auto& [k, v] : a) cout << k << ' ';
    cout << '\n';
}

void print(vi& a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << (i == a.size()-1 ? '\n' : ' ');
    }
}

void preprocess() {

}

vi fact(int x, int m) {
    vi r;
    for (int p = 1; p * p <= x; p++) {
        if (x % p == 0) {
            if (p <= m) r.pb(p);
            if (x / p != p && x / p <= m) r.pb(x / p);
        }
    }
    return r;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    vii ft(n);
    for (int i = 0; i < n; i++) {
        ft[i] = fact(a[i], m);
        // cout << "a: " << a[i] << '\n';
        // print(ft[i]);
    }

    int ans = INF;
    vi f(m+1, 0);
    int count = 0;

    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && count < m) {
            for (int p : ft[j]) {
                if (f[p] == 0) count++;
                f[p]++;
            }
            j++;
        }
        // cout << i << ' ' << j << '\n';
        // print(f);
        if (count == m) ans = min(ans, a[j-1] - a[i]);
        for (int p : ft[i]) {
            if (--f[p] == 0) count--;
        }
    }

    cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
    // freopen("name.in", "r", stdin);
    // freopen("name.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    preprocess();
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
    return 0;
}