// problem url: https://codeforces.com/gym/658641/problem/D
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

void solve() {
    int n, q; cin >> n >> q;
    string S; cin >> S;
    vi f(26, 0), cpf(26, 0);
    for (int i = 0; i < (int)S.size(); i++) {
        f[S[i]-'A']++;
        cpf[S[i]-'A']++;
    }
    for (int i = 0; i < q; i++) {
        int qi; cin >> qi;
        if (qi) {
            int j = 25;
            while (j >= 0 && cpf[j] == 0) j--;
            if (j >= 0) cpf[j]--;
        }
        else {
            int j = 0;
            while (j < n && cpf[j] == 0) j++;
            if (j < n) cpf[j]--;
        }   
    }
    string ans = "";
    for (int i = 0; i < (int)S.size(); i++) {
        int idx = S[i] - 'A';
        if (cpf[idx] < f[idx]) {
            cpf[idx]++;
            continue;
        }
        else ans += S[i];
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