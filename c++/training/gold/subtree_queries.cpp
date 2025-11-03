// problem url: https://cses.fi/problemset/task/1137
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector< vector<int> >;
using ll = long long;
using vl = vector<ll>;

vi sz, ord, pos;
vl v;
vii adj;

struct BIT {
    int n;
    vl bit, a;
    void init(int _n, vl _a) {
        n = _n; a = _a;
        bit.assign(n+1, 0);
        for (int i = 1; i <= n; i++) add(i, a[i]);
    }
    void add(int i, ll u) {
        for (; i <= n; i += i & (-i)) bit[i] += u;
    }
    void update(int i, ll x) {
        ll d = x - a[i];
        a[i] = x;
        add(i, d);
    }
    ll sum(int i) {
        ll r = 0;
        for (; i > 0; i -= i & (-i)) r += bit[i];
        return r;
    }
    ll range_sum(int l, int r) {
        return sum(r) - sum(l-1);
    }
    ll subtree_sum(int i, int len) {
        return range_sum(i, i + len - 1);
    }
};

int dfs(int u, int p) {
    pos[u] = (int)ord.size();
    ord.push_back(u);
    for (int v : adj[u]) {
        if (v == p) continue;
        sz[u] += dfs(v, u);
    }
    return sz[u];
}

void solve() {
    int n, q; cin >> n >> q;

    v.assign(n+1, 0);
    for (int i = 1; i <= n; i++) cin >> v[i];

    adj.assign(n+1, vi());
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    sz.assign(n+1, 1); 
    pos.assign(n+1, -1);
    ord.clear(); ord.push_back(-1);

    dfs(1, 0);

    vl uv; uv.resize(n+1);
    for (int i = 1; i <= n; i++) uv[i] = v[ord[i]];

    BIT bit; 
    bit.init(n, uv);

    for (int i = 0; i < q; i++) {
        int t, s; cin >> t >> s;
        if (t == 1) {
            ll x; cin >> x;
            bit.update(pos[s], x);
            continue;
        }
        cout << bit.subtree_sum(pos[s], sz[s]) << '\n';        
    }
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