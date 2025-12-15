// problem url: https://codeforces.com/gym/658641/problem/B
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

vi sieve() {
    const int MAXA = 1e6;
    vi prime(MAXA+5, 1);
    prime[0] = prime[1] = 0;
    for (int p = 2; p * p <= MAXA; p++) {
        if (prime[p]) {
            for (int x = p*p; x <= MAXA; x+=p) {
                prime[x] = 0;
            }
        }
    }
    return prime;
}

void solve() {
    int n; cin >> n;
    vi prime = sieve();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (!prime[x]) continue;
        int sx = 0;
        while (x) {
            sx += x % 10;
            x /= 10;
        }
        if (!prime[sx]) continue;
        ans++;
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