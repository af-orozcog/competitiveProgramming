#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

vector<vector<int>> dist;
vector<vector<pi>> dad;
vector<vector<char>> moves;
vector<vector<char>> matrix;

int movesX[] = {1,0,0,-1};
int movesY[] = {0,-1,1,0};
char mo[] = {'D','L','R','U'};

void bfs(int x, int y){
    int n = matrix.size();
    int m = matrix[0].size();
    dist[x][y] = 0;
    queue<pi> q;
    q.push({x,y});
    while(q.size()){
        pi da = q.front();
        q.pop();
        for(int i = 0; i < 4;++i){
            pi to = {da.first + movesX[i], da.second + movesY[i]};
            if(to.first < 0 || to.first >= n || to.second < 0 || to.second >= m) continue;
            if(matrix[to.first][to.second] == '#') continue;
            if(dist[to.first][to.second] != -1) continue;
            q.push({to.first,to.second});
            moves[to.first][to.second] = mo[i];
            dist[to.first][to.second] = dist[da.first][da.second] + 1;
            dad[to.first][to.second] = da;
        }
    }
}


string route(int x,int y, int toX,int toY){
    string rot = "";
    while(x != toX || y != toY){
        rot += moves[x][y];
        pi temp = dad[x][y];
        x = temp.first,y = temp.second;
    }
    reverse(rot.begin(),rot.end());
    return rot;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int cas = 1;
    while(t--){
        matrix.clear();
        dist.clear();
        moves.clear();
        dad.clear();
        int n,m;
        cin >> n >> m;
        swap(n,m);
        matrix.resize(n);
        dist.resize(n);
        moves.resize(n);
        dad.resize(n);
        int x,y;
        for(int i = 0; i < n;++i){
            matrix[i].resize(m);
            dist[i].resize(m,-1);
            moves[i].resize(m);
            dad[i].resize(m);
            for(int j = 0; j < m;++j){
                cin >> matrix[i][j];
                if(matrix[i][j] == '@') x = i,y = j;
            }
        }
        bfs(x,y);
        int maDi = 0;
        vector<pi> from;
        for(int i = 0; i < n;++i){
            for(int j = 0; j < m;++j){
                if(dist[i][j] == -1) continue;
                if(dist[i][j] > maDi){
                    from.clear();
                    from.push_back({i,j});
                    maDi = dist[i][j];
                }
                else if(dist[i][j] == maDi) from.push_back({i,j});
            }
        }
        vector<string> answers;
        for(auto &va:from){
            answers.push_back(route(va.first,va.second,x,y));
        }
        cout << "Case " << cas++ << ":\n";
        sort(answers.begin(),answers.end());
        cout << from.size() << " " << maDi << "\n";
        for(auto &show:answers)
            cout << show << "\n";
    }
    return 0;
}
