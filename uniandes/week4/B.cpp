#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

pi check(vector<pi> &see){
    for(int i = 0; i < 3;++i){
        for(int j = i+1; j < 3;++j){
            if(see[i].first != see[j].first && see[i].second != see[j].second){
                pi pos1 = {see[i].first,see[j].second};
                pi pos2 = {see[j].first,see[j].first};
                auto it = find(see.begin(),see.end(),pos1);
                if(it == see.end())
                    return pos1;
                else
                    return pos2;
            }
        }
    }
}

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    vector<pi> points;
    char matrix[n][m];
    for(int i = 0; i < n;++i){
        for(int j = 0; j < m;++j){
            char let;
            scanf(" %c",&let);
            if(let == '*')
                points.push_back({i+1,j+1});
            matrix[i][j] = let;
        }
    }
    pi ans = check(points);
    cout << ans.first << " " << ans.second << "\n";
    return 0;
}
