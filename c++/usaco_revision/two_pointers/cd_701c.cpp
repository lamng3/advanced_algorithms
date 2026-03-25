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
    int n; cin >> n;
    string s; cin >> s;

    set<char> uq;
    for (auto& c : s) uq.insert(c);
    int sz = uq.size();

    map<char, int> f;
    int ans = n+1;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && f.size() < sz) {
            f[s[j]]++;
            j++;
        }
        if (f.size() == sz) ans = min(ans, j - i);
        if (--f[s[i]] <= 0) f.erase(s[i]);
    }
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