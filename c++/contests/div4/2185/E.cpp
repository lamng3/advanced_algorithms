// problem url: 
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vii = vector< vector<int> >;
using pii = pair<int,int>;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define RFOR(i, n) for (int i = (n) - 1; i >= 0; i--)

#define fi first
#define se second
#define pb push_back

const int mod = 1e9+7;
const int INF = 1e9+7;

struct FenwickTree {
    int n;
    vi ft;
    void init(int _n) {
        n = _n;
        ft.assign(n+1, 0);
    }
    void add(int i, int v) {
        for (; i <= n; i+=i&-i) ft[i] += v;
    }
    int sum(int i) {
        int s = 0;
        for (; i > 0; i-=i&-i) s += ft[i];
        return s;
    }
};

struct Query {
    int mn, mx, idx;
    Query(int _mn, int _mx, int _idx) : mn(_mn), mx(_mx), idx(_idx) {}
    bool operator<(Query const& other) const {
        return mn < other.mn;
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vi a(n);
    REP(i, n) cin >> a[i];
    sort(a.begin(), a.end());

    vi b(m);
    REP(i, m) cin >> b[i];
    sort(b.begin(), b.end());

    // safe movement range [L, R] for each robot
    vector<pii> rng(n);
    REP(i, n) {
        int pos = a[i];
        int idx = lower_bound(b.begin(), b.end(), pos) - b.begin();
        int L = -INF, R = INF;
        // left spike exists
        if (idx > 0) {
            L = (b[idx - 1] - pos + 1);
        }
        // right spike exists
        if (idx < m) {
            R = (b[idx] - pos - 1);
        }
        rng[i] = make_pair(L, R);
    }

    // instructions
    string s; cin >> s;
    vi ist(k);
    REP(i, k) ist[i] = s[i] == 'L' ? -1 : 1;

    // range operations
    // at what point in time does robot[i] die
    // a[i] cross all x such that mn <= x <= mx
    // for each robot, check range of movements
    // check [mn, mx] intersects with range of movements [L[i], R[i]]

    // build queries: (mn_t, mx_t) for each time t
    vector<int> mnv(k), mxv(k);
    int pref = 0, mn = 0, mx = 0;
    REP(i, k) {
        pref += ist[i];
        mn = min(mn, pref);
        mx = max(mx, pref);
        mnv[i] = mn;
        mxv[i] = mx;
    }

    vector<pii> robots(n); // (L, R)
    vi compR(n);

    REP(i, n) {
        robots[i] = make_pair(rng[i].fi, rng[i].se);
        compR[i] = rng[i].se;
    }

    sort(robots.begin(), robots.end()); // L ascending

    // coordinate compression
    sort(compR.begin(), compR.end());
    compR.erase(unique(compR.begin(), compR.end()), compR.end());

    // build queries sorted by mn
    vector<Query> qs;
    qs.reserve(k);
    REP(i, k) qs.emplace_back(mnv[i], mxv[i], i);
    sort(qs.begin(), qs.end());

    FenwickTree ft; 
    ft.init((int)compR.size());

    vector<int> ans(k, 0);

    int ptr = 0, added = 0;
    for (int i = 0; i < k; i++) {
        Query& q = qs[i];

        // add all robots with L <= q.mn
        while (ptr < n && robots[ptr].fi <= q.mn) {
            int R = robots[ptr].se;
            int ridx = (int)(lower_bound(compR.begin(), compR.end(), R) - compR.begin()) + 1;
            ft.add(ridx, 1);
            added++;
            ptr++;
        }

        // count robots among added with R >= q.mx
        int pos = (int)(lower_bound(compR.begin(), compR.end(), q.mx) - compR.begin());

        // pos = number of R < q.mx, so BIT prefix sum up to pos gives count < q.mx
        int less = ft.sum(pos);
        ans[q.idx] = added - less;
    }

    // output answers for t = 1..k
    REP(i, k) cout << ans[i] << (i + 1 == k ? '\n' : ' ');
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