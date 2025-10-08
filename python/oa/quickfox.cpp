#include <bits/stdc++.h>
using namespace std;

vector<string> get_words(string s) {
    vector<string> r;
    string run = "";
    for (auto& x : s) {
        if (x == ' ') {
            r.push_back(run);
            run = "";
        }
        else run += x;
    }
    if (run != "") r.push_back(run);
    return r;
}

void solve(string text, string query, int k) {
    vector<string> wt = get_words(text);
    vector<string> wq = get_words(query);
    string key = wq[0];
    
    unordered_map<string, int> mp;
    int n = (int) wt.size();

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        mp[wt[i]]++;
        if (i <= k) continue;
        if (wt[i-k] == key) {
            bool ok = true;
            for (auto& w : wq) {
                if (mp.count(w) == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans.push_back(i-k);
        }
        mp[wt[i-k]]--;
        if (mp[wt[i-k]] <= 0) mp.erase(wt[i-k]);
    }

    // process [n-1-k ... n]
    for (int i = max(0, n-1-k); i < n; i++) {
        if (wt[i] == key) {
            bool ok = true;
            for (auto& w : wq) {
                if (mp.count(w) == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans.push_back(i);
        }
        mp[wt[i]]--;
        if (mp[wt[i]] <= 0) mp.erase(wt[i]);
    }

    for (auto& x : ans) cout << x << ' ';
}

int main() {
    // string text = "The quick brown fox is quick very very very quick fox";
    // string query = "quick fox";
    // int k = 2;
    string text; getline(cin, text);
    string query; getline(cin, query);
    int k; cin >> k;
    solve(text, query, k);
}