// problem url: https://codeforces.com/contest/1187/problem/E
// difficulty: 2100
// tags: dfs, dp, trees
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector< vector<int> > vii;

// undirected graph
vii g;

/*
    connected components in a tree
        * subtree of all white nodes 
*/
void solve() {
    int n; cin >> n;

    g.assign(n, vi());
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}