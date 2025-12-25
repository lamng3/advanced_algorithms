// problem url: https://codeforces.com/contest/2179/problem/D
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

vi generate_permutation(int n) {
    if (n == 1) return {1, 0};

    vi prev = generate_permutation(n-1);

    vi curr; 
    curr.reserve(1 << n);

    // map previous sequence x -> 2x + 1 to keep bit chains alive
    for (int x : prev) {
        curr.push_back(x * 2 + 1);
    }

    // prefix AND chain is broken here, so we want smallest numbers
    // fill with even numbers 0, 2, 4, ...
    for (int i = 0; i < (1 << (n-1)); i ++) {
        curr.push_back(i * 2);
    }
    
    return curr;
}

void solve() {
    int n; cin >> n;
    vi res = generate_permutation(n);
    for (int i = 0; i < res.size(); i++) cout << res[i] << (i == res.size()-1 ? '\n' : ' ');
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