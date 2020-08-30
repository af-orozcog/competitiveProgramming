#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d" ,&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        map<pair<int,int>,int> tr;
        tr[{0,0}] = 1;
        int ans = 1000000000;
        int le,ri;
        pair<int,int> act = {0,0};
        for(int i = 0, j = 2; i < n;++i,++j){
            char va; scanf(" %c",&va);
            if(va == 'L') --act.first;
            else if(va == 'R') ++act.first;
            else if(va == 'U') ++act.second;
            else --act.second;
            if(tr.count(act)){
                if(j - tr[act] < ans){
                    ans = j - tr[act];
                    le = tr[act];
                    ri = j;
                }
            }
            tr[act] = j;
            //cout << act.first << " " << act.second << "\n";
        }
        if(ans == 1000000000){puts("-1");continue;}
        printf("%d %d\n",le,ri-1);
    }
    return 0;
}
