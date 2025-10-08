// problem url: https://usaco.org/index.php?page=viewproblem2&cpid=1396
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

typedef long long ll;

int n;
int ft[MAXN];

void update(int k, int u) {
    for (; k <= n; k+=k&-k) ft[k] += u;
}

ll psum(int k) {
    ll s = 0;
    for (; k > 0; k-=k&-k) s += ft[k];
    return s;
}

void solve() {
    cin >> n;
    ll m; cin >> m;
    string s; cin >> s;
    vector<ll> a(n); 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}