// problem url: https://codeforces.com/contest/2148/problem/F
#include <bits/stdc++.h>
using namespace std;

bool cmp_pair(const pair<string,int>& L, const pair<string,int>& R) {
    if (L.first != R.first) return L.first < R.first;
    return L.second < R.second;
}

void solve() {
    int n; cin >> n;
    vector< vector<int> > a(n, vector<int>());
    vector<string> hsh(n, "");
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        a[i].reserve(k);
        string s;
        for (int j = 0; j < k; j++) {
            int x; cin >> x; 
            a[i].push_back(x);
            string sx = to_string(x);
            s += "#" + to_string((int)sx.size()) + sx;
        }
        hsh[i] = move(s);
    }

    vector< pair<string,int> > ord;
    ord.reserve(n);
    for (int i = 0; i < n; ++i) ord.push_back(pair<string,int>(hsh[i],i));
    
    sort(ord.begin(), ord.end(), cmp_pair);
    
    // build answer
    vector<int> ans = a[ord[0].second];
    int cursz = (int) ans.size();

    for (int i = 1; i < n; i++) {
        const vector<int>& cand = a[ord[i].second];
        if ((int) cand.size() <= cursz) continue;
        for (int j = cursz; j < (int) cand.size(); j++) ans.push_back(cand[j]);
        cursz = (int) ans.size();
    }

    // print answer
    int m = (int) ans.size();
    for (int i = 0; i < m; i++) cout << ans[i] << (i+1==m ? '\n' : ' ');
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