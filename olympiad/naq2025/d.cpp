// problem url: https://naq25.kattis.com/contests/naq25/problems/carlsmazesolvingalgorithm
#include <bits/stdc++.h>
using namespace std;

bool valid(int i, int j, int r, int c, const vector<string>& grid) {
    if (i < 0 || i >= r || j < 0 || j >= c) return false;
    if (grid[i][j] != '0') return false;
    return true;
}

string hash_location(int i, int j, int dir) {
    return to_string(i) + "#" + to_string(j) + "#" + to_string(dir);
}

void solve() {
    int r, c; cin >> r >> c;
    int is, js; cin >> is >> js;
    int ie, je; cin >> ie >> je;

    is--; js--;
    ie--; je--;

    vector<string> grid; grid.resize(r);
    for (int i = 0; i < r; i++) cin >> grid[i];

    int di[4] = {0, 1, 0, -1};
    int dj[4] = {1, 0, -1, 0};
    int dir = 0;

    unordered_set<string> seen;

    // check loops (visited a position with same i j and dir)
    while (is != ie || js != je) {
        string key = hash_location(is, js, dir);
        if (seen.count(key)) { cout << 0 << '\n'; return; }
        seen.insert(key);

        // turn left check empty square
        int leftdir = (dir + 3) % 4;
        int li = is + di[leftdir], lj = js + dj[leftdir];
        if (valid(li, lj, r, c, grid)) {
            is = li; js = lj;
            dir = leftdir;
            continue;
        }
        
        // check move forward
        int fi = is + di[dir], fj = js + dj[dir];
        if (valid(fi, fj, r, c, grid)) {
            is = fi; js = fj;
            continue;
        }

        // turn right
        dir = (dir + 1) % 4;
    }

    cout << 1 << '\n';
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