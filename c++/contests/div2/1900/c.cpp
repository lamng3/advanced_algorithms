// problem url: https://codeforces.com/contest/1900/problem/C
#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector< pair<int,int> > adj;
int ans;

void dfs(int v, int f) {
    int L = adj[v].first, R = adj[v].second;
    bool isleaf = (L == 0 && R == 0);
    if (isleaf) { ans = min(ans, f); return; }
    // check if going left or right needed a change
    if (L) dfs(L, f + (s[v-1] != 'L'));
    if (R) dfs(R, f + (s[v-1] != 'R'));
}

void solve() {
    cin >> n;
    cin >> s;
    adj.assign(n+1, make_pair(0,0));
    for (int i = 1; i <= n; i++) {
        int l, r; cin >> l >> r;
        adj[i] = make_pair(l,r);
    }
    // shortest path with minimal change
    ans = 1e6;
    dfs(1,0);
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