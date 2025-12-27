// problem url: https://leetcode.com/problems/minimum-time-to-complete-trips/description/
// difficulty: medium
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

const ll INF = 2e18;

bool check(const ll& minT, const vi& time, const int& trips) {
    ll count = 0;
    for (int t : time) {
        count += minT / t;
        if (count >= trips) return true;
    }
    return count >= trips;
}

ll find(const vi& time, const int& trips) {
    ll maxpos = INF;
    ll minT = maxpos;
    for (ll pos = maxpos; pos > 0; pos >>= 1) {
        while (check(minT - pos, time, trips)) {
            minT -= pos;
        }
    }
    return minT;
}

ll minimumTime(vi& time, int trips) {
    ll ans = find(time, trips);
    return ans;
}

/*
inp:
3
1 2 3
5
out:
3
*/
void solve() {
    int n; cin >> n;
    vi time(n); 
    for (int i = 0; i < n; i++) cin >> time[i];
    int trips; cin >> trips;
    ll ans = minimumTime(time, trips);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}