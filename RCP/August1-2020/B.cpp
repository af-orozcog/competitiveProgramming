#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define MAX 100005
#define ff first
#define ss second
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

int h,w,r,s;

vector<pii> v;
int cost[30][30];
int idx[30][30][5630];
vector<double> d;
set<int> endes;
vector<vector<pair<int,double>>> g;
priority_queue<pair<double,int>> q;

int dist2(pii a, pii b){
    int x = a.ff-b.ff;
    int y = a.ss-b.ss;
    return x*x+y*y;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>h>>w>>r>>s;
    string act;
    for(int i = 0; i<h; ++i){
        cin>>act;
        for(int j =0; j<w; ++j){
            if(act[j]=='.')continue;
            v.push_back({i,j});
            cost[i][j] = act[j]-'0';
        }
    }
    sort(v.begin(),v.end());
    int id = 0;
    for(int i = 0; i<v.size(); ++i){
        for(int j = 0; j<=5625; ++j){
            idx[v[i].ff][v[i].ss][j]=id++;
            if(i==v.size()-1)
                endes.insert(idx[v[i].ff][v[i].ss][j]);
        }
    }
    g.resize(id+5);
    d.resize(id+5,1000000000);
    for(int  i =0; i<v.size(); ++i){
        for(int j = 0; j<v.size(); j++){
            if(i==j)continue;
            for(int k = 0; k<=5625; ++k){
                if(dist2(v[i],v[j])<=r*r&&k>=cost[v[j].ff][v[j].ss]){
                    g[idx[v[i].ff][v[i].ss][k]].push_back({idx[v[j].ff][v[j].ss][k-cost[v[j].ff][v[j].ss]],sqrt((double)dist2(v[i],v[j]))});
                }
            }
        }
    }

    q.push({0,idx[v[0].ff][v[0].ss][max(0,min(5625,s-cost[v[0].ff][v[0].ss]))]});
    while(q.size()){
        pair<double,int> f = q.top();
        q.pop();
        if(d[f.second] < -f.first) continue;
        for(auto va:g[f.second]){
            if(va.second-f.first < d[va.first]){
                d[va.first] = va.second-f.first;
                if(!endes.count(va.first))
                    q.push({-d[va.first],va.first});
            }
        }
    }
    double ans = 1000000000;
    for(int i = 0; i <= 5625; ++i)
        ans = min(ans,d[idx[v.back().ff][v.back().ss][i]]);
    if(ans == 1000000000.0) cout << "impossible\n";
    else cout << fixed << setprecision(10) <<ans << "\n";
    return 0;
}
