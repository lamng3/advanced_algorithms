// problem url: 
#include <bits/stdc++.h>
using namespace std;

vector<int> operations(const int& n, const string& s) {
    vector<int> ops;
    int run = s[0] == 'A' ? 1 : -1;
    for (int i = 1; i < n; i++) {
        int sign = (run > 0) ? 1 : -1;
        if (s[i] == s[i-1]) run += sign;
        else {
            ops.push_back(run);
            run = -sign;
        }
    }
    ops.push_back(run);
    return ops;
}

int flog2(unsigned long long x) {
    return 63 - __builtin_clzll(x);
}

int query(long long a, const vector<int>& ops) {
    int time = 0;
    while (a > 0) {
        for (auto& op : ops) {
            if (op > 0) {
                if (a <= op) return time + a;
                a -= op;
                time += op;
            }
            else {
                int t = -op;
                // log
                int msb = flog2((unsigned long long)a);
                int sh = min(t, msb + 1);
                a >>= sh;
                time += sh;
                if (a == 0) return time;
            }
        }
    }
    return time;
}

void solve() {
    /*
        compress string s
        consecutive chain of same actions
    */
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<int> ops = operations(n, s);
    while (q--) {
        long long a; cin >> a;
        int time = query(a, ops);
        cout << time << '\n';
    }
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