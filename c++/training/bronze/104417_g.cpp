// problem url: https://codeforces.com/gym/104417/problem/G
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ll = long long;

struct DSU {
    vi parent, sz;
    void init(int n, vi a) {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
};

void solve() {
    // i - j = ai - aj
    // ai - i = aj - j
    int n; cin >> n;
    vi a(n); for (int i = 0; i < n; i++) cin >> a[i];
    DSU dsu; dsu.init(n, a);
    unordered_map<int, int> pos;
    for (int i = 0; i < n; i++) {
        int key = a[i] - i;
        if (pos.count(key)) {
            int id = pos[key];
            dsu.unite(id, i);
        }
        else pos[key] = i;
    }
    unordered_map< int, vector<int> > scc;
    for (int i = 0; i < n; i++) {
        int pi = dsu.find(i);
        scc[pi].push_back(a[i]);
    }
    ll best = 0;
    for (auto it = scc.begin(); it != scc.end(); it++) {
        vi& nodes = it->second;
        sort(nodes.begin(), nodes.end());
        int m = (int) nodes.size();
        for (int i = m-1; i >= 1; i -= 2) {
            ll edge = (ll) nodes[i] + nodes[i-1];
            if (edge > 0) best += edge;
        }
    }
    cout << best << '\n';
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