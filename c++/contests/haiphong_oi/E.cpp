// problem url: https://codeforces.com/gym/658641/problem/E
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ll = long long;
using vl = vector<ll>;

vi sieve() {
    vi r;
    const int MAXP = 1e5;
    vi prime(MAXP+5, 1);
    prime[0] = prime[1] = 0;
    for (int p = 2; p * p <= MAXP; p++) {
        if (prime[p]) {
            r.push_back(p);
            for (int x = p*p; x <= MAXP; x+=p) {
                prime[x] = 0;
            }
        }
    }
    return r;
}

ll count_divisors(int x, const vi& primes) {
    ll r = 1;
    for (int p : primes) {
        if (p * p > x) break;
        if (x % p != 0) continue;
        int f = 0;
        while (x % p == 0) {
            x /= p;
            f++;
        }
        r *= (ll)(f+1);
    }
    if (x > 1) r *= 2;
    return r;
}

void solve() {
    int n; cin >> n;
    // if (n > 1000) return;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vi primes = sieve();

    vl dc(n, 0);
    for (int i = 0; i < n; i++) dc[i] = count_divisors(a[i], primes);

    vi ans(n, n+1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (dc[j] < dc[i]) ans[j] = min(ans[j], i);
        }
    }

    for (int i = 0; i < n; i++) cout << (ans[i] == n+1 ? -1 : a[ans[i]]) << (i == n-1 ? '\n' : ' ');
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