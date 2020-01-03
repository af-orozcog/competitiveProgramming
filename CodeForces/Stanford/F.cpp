#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool check(string ar1[],string ar2[], string &key, int t){
    for(int i = 0; i < t;++i){
        //if(key.size() > ar1[i].size())return 0;
        for(int j = 0; j < ar1[i].size();++j){
            if(j < key.size()){
                char le = ((ar1[i][j] + key[j])%26)+'A';
                if(le != ar2[i][j]) return 0;
            }
            else{
                char le = ((ar1[i][j] + ar2[i][j-(int)key.size()])%26)+'A';
                if(le != ar2[i][j]) return 0;
            }
        }
    }
    return 1;
}


int main(){
    int t;
    while(scanf(" %d",&t) && t){
        string ar1[t],ar2[t];
        for(int i = 0; i < t;++i)
            cin >> ar1[i] >> ar2[i];
        string key = "";
        bool found = 0;
        for(int i = 0; i < ar1[0].size() && !found;++i){
            key += 'A'+((ar2[0][i]-ar1[0][i]+26)%26);
            //cout << key << endl;
            found = check(ar1,ar2,key,t);
        }
        if(found) cout << key << endl;
        else cout << "Impossible" << endl;
    }
}
