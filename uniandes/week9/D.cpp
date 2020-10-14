#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

vector<vector<int>> movesX = {{0,0,1,-1,1,1,-1-1},{1,1,-1,-1}};
vector<vector<int>> movesY = {{1,-1,0,0,-1,1,-1,1},{-1,1,-1,1}};

void bfs(int x, int y, map<pi,int> dist, int moves){
    queue<pi> q;
    q.push({x,y});
    dist[{x,y}] = 0;
    while(q.size()){
        pi dad = q.front();
        q.pop();
        for(int i = 0; i < movesX[moves].size();++i){
            pi next = {dad.first+movesX[moves][i],dad.second+movesY[moves][i]};
            if(next.first < 1 || next.first > 8 || next.second < 1 || next.second > 8) continue;
            if(dist.count(next)) continue;
            dist[next] = dist[dad]+1;
        }
    }
}

int main(){
    int rs,cs,r,c;
    scanf(" %d %d %d %d",&rs,&cs,&r,&c);
    printf("%d ",abs(rs-r)+abs(cs-c));
    map<pi,int> dist;
    bfs(rs,cs,dist,1);
    if(!dist.count({r,c})) dist[{r,c}] = 0;
    printf("%d ",dist[{r,c}]);
    dist.clear();
    bfs(rs,cs,dist,0);
    printf("%d\n",dist[{r,c}]);
    return 0;
}
