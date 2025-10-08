/*
this quick fox problem requires all words in query in order

text = "The quick brown fox brown fox fox quick"
query = "quick fox brown"
k = 3
output = [1]
*/
#include <bits/stdc++.h>
using namespace std;

vector<string> get_words(string s) {
    vector<string> res;
    string run = "";
    for (int i = 0; i < s.size(); i++) {
        char x = s[i];
        if (x == ' ') {
            res.push_back(run);
            run = "";
        }
        else run += x;
    }
    if (run != "") res.push_back(run);
    return res;
}

// O((M + K) * logK)
bool compare_arrays(vector<string>& sub, vector<string>& wq) {
    int m = (int) wq.size();
    int k = (int) sub.size();

    // store indices
    unordered_map< string, set<int> > pos;
    for (int i = 0; i < k; i++) { // O(K logK)
        pos[sub[i]].insert(i);
    }

    int currentid = -1;
    for (int i = 0; i < m; i++) { // O(M)
        string w = wq[i];
        set<int>& ids = pos[w];
        // find first index >= currentid
        auto it = ids.lower_bound(currentid); // O(logK)
        if (it == ids.end()) return false;
        currentid = *it + 1;
    }
    return true;
}

void solve(string text, string query, int k) {
    // O(N * (M + K) * logK)
    vector<string> wt = get_words(text);
    vector<string> wq = get_words(query);
    string key = wq[0];

    int n = (int) wt.size();
    int m = (int) wq.size();

    unordered_set<string> qset;
    for (int i = 0; i < m; i++) qset.insert(wq[i]);

    vector<int> ans;
    for (int i = 0; i < n; i++) { // O(N)
        if (wt[i] == key) {
            vector<string> sub;
            for (int j = 0; j <= k; j++) { // O(K)
                if (i + j < n && qset.count(wt[i+j])) {
                    sub.push_back(wt[i+j]);
                }
            }
            bool ok = compare_arrays(sub, wq); // O((M + K) * logK)
            if (ok) ans.push_back(i);
        }
    }

    for (int x : ans) cout << x << ' ';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string text; getline(cin, text);
    string query; getline(cin, query);
    int k; cin >> k;
    solve(text, query, k);
    return 0;
}

