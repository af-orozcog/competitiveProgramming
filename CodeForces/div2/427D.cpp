#include<bits/stdc++.h>
using namespace std;

vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
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

vector<int> suffix_array_construction(string &s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    s.pop_back();
    return sorted_shifts;
}

vector<int> lcp_construction(string const& s, vector<int> const& p) {
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}

vector<int> z_algorithm (string &s) {
  int n = s.size();
  vector<int> z(n);
  int x = 0, y = 0;
  for(int i = 1; i < n; ++i) {
    z[i] = max(0, min(z[i-x], y-i+1));
    while (i+z[i] < n && s[z[i]] == s[i+z[i]])
      x = i, y = i+z[i], z[i]++;
  }
  return z;
}

int check(string &re1, string &re2){
    string see = re1+ "$"+re2;
    vector<int> z = z_algorithm(see);
    int co = 0;
    for(int i = re1.size();i < z.size();++i){
        if(z[i] == (int)re1.size()) ++co;
    }
    return co == 1;
}


int main(){
    string re1,re2;
    cin >> re1 >> re2;
    if(re1.size() == 1){
        int va = count(re2.begin(),re2.end(),re1[0]);
        if(va == 1) puts("1");
        else puts("-1");
        return 0;
    }
    vector<int> p = suffix_array_construction(re1);
    vector<int> lcp = lcp_construction(re1,p);
    int ans = 1000000000;
    int ma = lcp[(int)lcp.size()-1];
    for(int j = ma+1; j <= (int)re1.size()-p[(int)re1.size()-1];++j){
        string send = re1.substr(p[(int)re1.size()-1],j);
        int va = check(send,re2);
        if(va == 1){ans = min(ans,j);break;}
        if(!va) break;
    }
    for(int i = 0; i < lcp.size();++i){
        if(i == 0){
            int ma = lcp[i];
            for(int j = ma+1; j <= (int)re1.size()-p[i];++j){
                string send = re1.substr(p[i],j);
                int va = check(send,re2);
                if(va == 1){ans = min(ans,j);break;}
                if(!va) break;
            }
        }
        else{
            int ma = max(lcp[i],lcp[i-1]);
            for(int j = ma+1; j <= (int)re1.size()-p[i];++j){
                string send = re1.substr(p[i],j);
                int va = check(send,re2);
                if(va == 1){ans = min(ans,j);break;}
                if(!va) break;
            }
        }
    }
    if(ans == 1000000000) puts("-1");
    else printf("%d\n",ans);
    return 0;
}
