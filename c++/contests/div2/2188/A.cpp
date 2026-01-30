// problem url: https://codeforces.com/contest/2188/problem/A
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
    
    vi p(n+1);
    
    int d = 0;
    for (int i = n; i >= 1; i-=2) {
        p[i] = n - d;
        d++;
    }

    d = 1;
    for (int i = n-1; i >= 1; i-=2) {
        p[i] = d;
        d++;
    }

    for (int i = 1; i <= n; i++) cout << p[i] << (i == n ? '\n' : ' ');
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