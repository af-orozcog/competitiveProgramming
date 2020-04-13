/**
* El hombre bocachico nos bendiga
* y la arawana nos de fuerza
*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define MAX 100000
using namespace std;
typedef pair<ll,ll> pi;

ll dist[1000][1000];
int main(){
    //cout << "lil" << endl;
    int movesX[] = {0,0,1,-1};
    int movesY[] = {1,-1,0,0};
    vector<vector<ll>> matrix;
    string re;
    while(getline(cin,re)){
        stringstream ss;
        ss << re;
        ll num;
        vector<ll> nums;
        while(ss >> num){
            nums.pb(num);
           // cout << num << endl;
        }
        matrix.pb(nums);
    }
    //cout << "here" << endl;
    priority_queue<pair<ll,pi>> q;
    q.push({0,{0,0}});
    for(int i = 0; i < 1000;++i){
        for(int j = 0; j < 1000;++j) dist[i][j] = 10000000000ll;
    }
    dist[0][0] = 0;
    while(q.size()){
        int f = -q.top().first; pi from = q.top().second;
        q.pop();
        if(f > dist[from.first][from.second]) continue;
        for(int i = 0; i < 4;++i){
            int toY = from.second + movesY[i];
            int toX = from.first + movesX[i];
            if(toX > 999 || toX < 0) continue;
            if(toY > 999 || toY < 0) continue;
            if(dist[toX][toY] > dist[from.first][from.second] + matrix[from.first][from.second]){
                dist[toX][toY] = dist[from.first][from.second] + matrix[from.first][from.second];
                q.push({-dist[toX][toY],{toX,toY}});
            }
        }
    }
    cout << dist[999][999] + matrix[999][999] << endl;
    return 0;
}
