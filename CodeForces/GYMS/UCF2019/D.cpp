#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,p;
    cin >> n >> p;
    unordered_map<string,vector<int>> fr;
    for(int i = 1; i < n;++i){
        string re;
        cin >> re;
        fr[re].push_back(i);
    }
    for(auto &va:fr){
        if(va.first.rfind("SPECIAL",0) != 0)
            va.second.push_back(n);
    }
    //cout << "what" << endl;
    int deN;
    cin >> deN;
    queue<pair<string,int>> q;
    vector<int> pl(p,-1);
    for(int i = 0; i < deN;++i){
        string re;int ty;
        cin >> ty >> re;
        q.push({re,ty});
    }
    int turn = 0;
    while(1){
        pair<string,int> see = q.front();
        q.pop();
        q.push(see);
        if(see.second == 3)
            pl[turn] = fr[see.first][0];
        else if(see.second == 1){
            int index = lower_bound(fr[see.first].begin(),fr[see.first].end(),pl[turn]+1) -fr[see.first].begin();
            pl[turn] = fr[see.first][index];
        }
        else{
            int index = lower_bound(fr[see.first].begin(),fr[see.first].end(),pl[turn]+1) -fr[see.first].begin();
            pl[turn] = fr[see.first][index];
            if(pl[turn] != n){
                int index = lower_bound(fr[see.first].begin(),fr[see.first].end(),pl[turn]+1) -fr[see.first].begin();
                pl[turn] = fr[see.first][index];
            }
        }
        if(pl[turn] == n){
            cout << turn +1 << endl;
            break;
        }
        turn += 1;
        turn = turn % p;
    }
    return 0;
}
