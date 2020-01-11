#include<bits/stdc++.h>
using namespace std;

vector<int> suffixArray(string &s){
    int n = s.size();
    int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> lcpC(string const &s,vector<int> const &p){
    int n = s.size();
    vector<int> rank(n,0);
    for(int i = 0;i < n;++i)
        rank[p[i]] = i;
    int k = 0;
    vector<int> lcp(n-1,0);
    for(int i = 0; i < n;++i){
        if(rank[i] == n -1){
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while(i + k < n && j + k < n && s[i+k] == s[j+k])
            ++k;
        lcp[rank[i]] = k;
        if(k)
            --k;
    }
    return lcp;
}

int z_algorithm (string &s, int sum) {
  int n = s.size();
  vector<int> z(n);
  int x = 0, y = 0;
  for(int i = 1; i < n; ++i) {
    z[i] = max(0, min(z[i-x], y-i+1));
    while (i+z[i] < n && s[z[i]] == s[i+z[i]])
      x = i, y = i+z[i], z[i]++;
  }
  int ans = 0;
   for(int i = sum; i < n;++i){
        if(z[i] == sum) ++ans;
   }
   return ans;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        string re; cin >> re;
        re += "$";
        vector<int> p = suffixArray(re);
        p.erase(p.begin());
        re.pop_back();
        vector<int> lcp = lcpC(re,p);
        //for(auto va: lcp) printf("%d ",va);
        //puts("");
        int big = 0, who;
        for(int i = 0; i < lcp.size();++i){
            if(lcp[i] > big)
                big = lcp[i],who = p[i];
        }
        if(big == 0){puts("No repetitions found!");continue;}
        string look = re.substr(who,big);
        string send = look + "$" + re;
        int ans = z_algorithm(send,look.size());
        cout << look << " " << ans << "\n";
    }
    return 0;
}
