/*
    gemini generated solution
    complexity: O(nlogn) (original solution: O(n^2))
    a good problem in the future to practice Segment Tree + Sweep Line
    note: overengineering for the original problem :)
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;

struct Event {
    int x, y1, y2, type;
    bool operator<(const Event& other) const {
        if (x != other.x) return x < other.x;
        return type > other.type; // Process additions before removals
    }
};

class SegmentTree {
    vi tree, lazy;
    int n;
public:
    SegmentTree(int size) : n(size) {
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }
    void update(int node, int start, int end, int l, int r, int val) {
        if (start > end || start > r || end < l) return;
        if (start >= l && end <= r) {
            lazy[node] += val;
            tree[node] += val;
            return;
        }
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]) + lazy[node];
    }
    int query() { return tree[1]; }
};

class Solution {
public:
    bool check(int s, int n, vii& bl, vii& tr) {
        if (s <= 0) return true;
        vector<Event> events;
        vi y_coords;

        for (int i = 0; i < n; ++i) {
            int x1 = bl[i][0], y1 = bl[i][1];
            int x2 = tr[i][0] - s, y2 = tr[i][1] - s;
            if (x1 <= x2 && y1 <= y2) {
                events.push_back({x1, y1, y2, 1});
                events.push_back({x2, y1, y2, -1});
                y_coords.push_back(y1);
                y_coords.push_back(y2);
            }
        }

        if (events.empty()) return false;

        // Coordinate Compression for Y-axis
        sort(y_coords.begin(), y_coords.end());
        y_coords.erase(unique(y_coords.begin(), y_coords.end()), y_coords.end());
        auto get_idx = [&](int y) {
            return lower_bound(y_coords.begin(), y_coords.end(), y) - y_coords.begin();
        };

        sort(events.begin(), events.end());
        SegmentTree st(y_coords.size());

        for (auto& e : events) {
            st.update(1, 0, y_coords.size() - 1, get_idx(e.y1), get_idx(e.y2), e.type);
            if (st.query() >= 2) return true;
        }
        return false;
    }

    ll largestSquareArea(vii& bl, vii& tr) {
        int n = bl.size();
        int low = 1, high = 1e9, ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, n, bl, tr)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return (ll)ans * ans;
    }
};