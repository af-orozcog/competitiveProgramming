#include<bits/stdc++.h>
using namespace std;

vector<int> suffixArray(string &s){
    int n = s.size();
    int alphabet = 256;
    vector<int> p(n),c(n),cnt(max(n,alphabet),0);
    for(int i = 0; i < n;++i)
        ++cnt[s[i]];
    for(int i = 1; i < alphabet;++i)
        cnt[i] += cnt[i-1];
    for(int i = 0; i < n;++i)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for(int i = 1; i < n;++i){
        if(s[p[i]] != s[p[i-1]])
            ++classes;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n),cn(n);
    for(int h = 0; (1 << h) < n;++h){
        for(int i = 0; i < n;++i){
            pn[i] = p[i] - (1<<h);
            if(pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(),cnt.begin() + classes,0);
        for(int i = 0; i < n;++i)
            ++cnt[c[pn[i]]];
        for(int i = 1; i < classes;++i)
            cnt[i] += cnt[i-1];
        for(int i = n-1; i > -1;--i)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for(int i = 1; i < n;++i){
            pair<int,int> cur = {c[p[i]],c[(p[i] + (1<<h))%n]};
            pair<int,int> prev = {c[p[i-1]],c[(p[i-1] + (1<<h))%n]};
            if(cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> lcpC(string &s,vector<int> &p){
    int n = s.size();
    vector<int> rank(n);
    for(int i = 0; i < n;++i)
        rank[p[i]] = i;
    vector<int> lcp(n-1);
    int k = 0;
    for(int i = 0; i < n;++i){
        if(rank[i] == n-1){
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


int main(){
    string re1,re2;
    bool fi = 0;
    while(cin >> re1 >> re2){
        if(fi) puts("");
        fi = 1;
        string send = re1 +"$" + re2 + "$";
        vector<int> p = suffixArray(send);
        vector<int> lcp = lcpC(send,p);
        int big = 0;
        vector<int> who;
        vector<bool> dp(re1.size(),0);
        for(int i = 0; i < lcp.size();++i){
            int mi = min(p[i],p[i+1]),ma = max(p[i],p[i+1]);
            //cout << min(lcp[i],(int)re1.size()-mi) << endl;
            if(mi < re1.size() && ma > re1.size() && min(lcp[i],(int)re1.size()-mi) > big){
                who.clear();
                big = min(lcp[i],(int)re1.size()-mi);
                who.push_back(mi);
                fill(dp.begin(),dp.end(),0);
                dp[mi] = 1;
            }
            else if(mi < re1.size() && ma >= re1.size() && min(lcp[i],(int)re1.size()-mi) == big && !dp[mi])
                who.push_back(mi), dp[mi] = 1;
        }
        if(big == 0){puts("No common sequence.");continue;}
        unordered_set<string> dif;
        for(int i = 0; i < who.size();++i){
            string show = re1.substr(who[i],big);
            if(!dif.count(show))
                cout << re1.substr(who[i],big) << "\n",dif.insert(show);
        }
    }
    return 0;
}
