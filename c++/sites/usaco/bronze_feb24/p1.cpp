// problem url: https://usaco.org/index.php?page=viewproblem2&cpid=1395
#include <bits/stdc++.h>
using namespace std;

void solve() {
    /*
        leading zeros not allowed
        remove single digit to make it non-palindrome
    */
   string s; cin >> s;
   cout << (s[(int)s.size()-1] != '0' ? 'B' : 'E') << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
    return 0;
}