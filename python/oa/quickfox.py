from collections import *

def get_words(text):
    return text.split(' ')
    
def solve(text, query, k):
    wt = get_words(text)
    wq = get_words(query)
    key = wq[0]
    
    ans = []
    
    n = len(wt)
    mp = defaultdict(int)
    for i in range(n):
        mp[wt[i]] += 1
        if i <= k: continue
        if wt[i-k] == key:
            ok = True
            for w in wq:
                if w not in mp:
                    ok = False
                    break
            if ok: ans.append(i-k)
        mp[wt[i-k]] -= 1
        if mp[wt[i-k]] <= 0: del mp[wt[i-k]]
            
    for i in range(n-1-k, n):
        if wt[i] == key:
            ok = True
            for w in wq:
                if w not in mp:
                    ok = False
                    break
            if ok: ans.append(i)
        mp[wt[i]] -= 1
        if mp[wt[i]] <= 0: del mp[wt[i]]
            
    return ans

text = "The quick brown fox is quick very very very quick fox"
query = "quick fox"
k = 2
ans = solve(text, query, k)
print(ans)