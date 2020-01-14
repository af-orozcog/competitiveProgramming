#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll M = 1000000007;
const ll multy = 365;

vector<int> SA(vector<int> &s) {
    int n = s.size();
    const int alphabet = 400;
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

int main(){
    int n;
    scanf(" %d",&n);
    int staSiz[n],beg[n];
    vector<int> con;
    for(int i = 0; i < n;++i) {
        int temp;
        scanf(" %d",&staSiz[i]);
        beg[i] = con.size();
        for(int j = 0; j < staSiz[i];++j){
            scanf(" %d",&temp);con.push_back(temp);
        }
        con.push_back(399);
    }
    vector<int> sufA = SA(con);
    vector<int> rank(con.size());
    for(int i = 0; i < con.size();++i)
        rank[sufA[i]] = i;
    priority_queue<pair<int,int>> q;
    for(int i = 0; i < n;++i)
        q.push({-rank[beg[i]],i});
    ll ans = 0;
    while(q.size()){
        int f1 = -q.top().first, f2 = q.top().second;
        q.pop();
       // cout << con[beg[f2]] << endl;
        ans += con[beg[f2]];
        ans = ans % M;
        ans *= multy;
        ans = ans % M;
        --staSiz[f2];
        if(staSiz[f2]){++beg[f2]; q.push({-rank[beg[f2]],f2});}
    }
    cout << ans << endl;
    return 0;
}
