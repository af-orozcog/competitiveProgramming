#include<bits/stdc++.h>
using namespace std;


char matrix[12][12] = {
{0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0,0,1,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,-1,-1,0,0,0,0,0},
{0,0,0,0,0,-1,-1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0},
{0,-1,-1,0,0,0,0,0,0,-1,-1,0},
{0,-1,1,0,0,0,0,0,0,1,-1,0},
{0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0}
};

int movesX[] = {1,-1,0,0};
int movesY[] = {0,0,1,-1};

char wut[] = {'R','L','D','U'};

vector<char> bfs(vector<pair<int,int>> pos){
    int one = 0;
    int two = 0;
    for(auto va: pos){
        one += (1<<va.first);
        two += (1<<va.second);
    }
    queue<int,int> q;
    q.push({one,two});
    while(q.size()){
        pair<int,int> top = q.front();
        q.pop();
        for(int i = 0; i < 4;++i){

        }
    }
    int ans = 1000000000;
    vector<char> send;
    for(int i = 0; i < 12;++i){
        for(int j = 0; j < 12;++j){
            if(matrix[i][j] == 1 && dist[i][j] < ans && dist[i][j] != -1){
                send.clear();
                ans = dist[i][j];
                int r = i,c = j;
                while(dad[r][c].first != -1){
                    send.push_back(movee[r][c]);
                    int neR = dad[r][c].first;
                    int neC = dad[r][c].second;
                    r = neR;
                    c = neC;
                }
            }
        }
    }
    if(send.size())
        reverse(send.begin(),send.end());
    return send;
}

int main(){
    int l;
    scanf(" %d",&l);
    while(l--){
        int r,c;
        scanf(" %d %d",&r,&c);
        --r,--c;
        vector<char> ans = bfs(r,c);
        printf("%d\n",(int)ans.size());
        for(auto va:ans)
            printf("%c",va);
        puts("");
    }
    return 0;
}
