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

typedef long long F;
const int MAXV = 4000;
const int MAXE = 100000;
const F F_INF = 100000000000000;
//clase para manejar de forma eficiente el maxflow
class MaxFlow {
public:
    int V, E;

    MaxFlow(int V) : V(V), E(0) {
        memset(start, -1, sizeof(start));
    }

    void add_edge(int x, int y, F c) {
        cap[E] = c; flow[E] = 0; v[E] = y; next[E] = start[x]; start[x] = E; ++E;
	//para arcos dirigidos c = 0 aca abajo
        cap[E] = 0; flow[E] = 0; v[E] = x; next[E] = start[y]; start[y] = E; ++E;
    }

    bool BFS(int, int);
    F DFS(int, int, F);
    F maxflow(int, int);

    vector<pair<int, int>> get_flows();

private:
    int start[MAXV], next[MAXE], v[MAXE];
    int used[MAXV], level[MAXV];
    F cap[MAXE], flow[MAXE];
};

vector<pair<int, int>> MaxFlow::get_flows() {
    vector<pair<int, int>> ret;
    for (int i = 0; i < V; ++ i)
        for (int j = start[i]; j != -1; j = next[j])
            if (flow[j] > 0)
                ret.push_back({i, v[j]});
    return ret;
}
//funcion para contruir el grafo de nivel
bool MaxFlow::BFS(int s, int t) {
    memset(level, -1, sizeof(level));
    queue<int> q;
    q.push(s); level[s] = 0;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = start[x]; i != -1; i = next[i])
            if (level[v[i]] == -1 && cap[i] > flow[i]) {
                q.push(v[i]);
                level[v[i]] = level[x] + 1;
            }
    }
    return (level[t] != -1);
}

//funcion para hallar el blocking flow
F MaxFlow::DFS(int s, int t, F f) {
    if (s == t) return f;
    for (int &i = used[s]; i != -1; i = next[i])
        //if (level[v[i]] > level[s] && cap[i] > flow[i]) { // should be same
        if (level[v[i]] == level[s] + 1 && cap[i] > flow[i]) {
            F temp = DFS(v[i], t, min(f, cap[i] - flow[i]));
            if (temp > 0) {
                flow[i] += temp; flow[i^1] -= temp;
                return temp;
            }
        }
    return 0;
}
// funcion para hallar el maxflow entre s = source y t = target
F MaxFlow::maxflow(int s, int t) {
    while (BFS(s, t)) {
        for (int i = 0; i < V; ++ i)
            used[i] = start[i];
        while (DFS(s, t, F_INF) != 0);
    }
    F ret = 0;
    for (int i = start[s]; i != -1; i = next[i])
        ret += flow[i];
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t,x;
    cin>>n;
    MaxFlow mf = MaxFlow(2001);
    for(int i =1; i<=n; ++i){
        cin>>t;
        mf.add_edge(1000+i,2000,1);
        while(t--){
            cin>>x;
            mf.add_edge(x,1000+i,1);
        }
    }
    for(int i = 1; i<=1000; ++i){
        mf.add_edge(0,i,1);
        int flow = mf.maxflow(0,2000);
        if(flow==n){
            cout<<i+1<<"\n";
            return 0;
        }
    }
    return 0;
}
