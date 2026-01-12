// problem url: https://codeforces.com/contest/2162/problem/B
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
#define pb push_back

const int mod = 1e9+7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int FULL = 1 << n;

    REP(i, FULL) {
        string p = "", x = "";
        vi pos; pos.clear();
        REP(j, n) {
            if (i & (1 << j)) {
                p += s[j];
                pos.pb(j);
            }
            else x += s[j];
        }
        
        bool ok = true;
        
        FOR(j, 1, (int)p.size()-1) {
            if (p[j-1] > p[j]) {
                ok = false;
                break;
            }
        }

        int m = (int)x.size();
        REP(j, m) {
            if (x[j] != x[m-1-j]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            cout << (int)p.size() << '\n';
            REP(j, pos.size()) {
                cout << pos[j] + 1 << (j == (int)pos.size() - 1 ? "" : " ");
            }
            cout << '\n';
            return;
        }
    }
    cout << -1 << '\n';
    return;
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