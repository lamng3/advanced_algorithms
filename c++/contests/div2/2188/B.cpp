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
#define pb push_back

const int mod = 1e9+7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    if (n == 1) {
        cout << 1 << '\n';
        return;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) ans += s[i] == '1';

    // 10001

    int run = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            // process run as a sequence of 0
            // 010010
            ans += run / 3 + (run % 3 != 0);
            run = 0;
        }
        else {
            bool pok = i > 0 ? s[i-1] == '0' : 1;
            bool nok = i < n-1 ? s[i+1] == '0' : 1;
            if (pok && nok) run++; 
        }
    }
    if (run) ans += run / 3 + (run % 3 != 0);

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