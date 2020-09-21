#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

unordered_set<string> wut;

int main(){
    freopen("triatrip.in", "r", stdin);
    freopen("triatrip.out", "w", stdout);
    int n;
    scanf(" %d",&n);
    int matrixN[n][n];
    int matrixI[n][n];
    memset(matrixI,0,sizeof(matrixI));
    for(int i = 0; i < n;++i){
        for(int j = 0; j < n;++j){
            char va;
            scanf(" %c",&va);
            matrixN[i][j] = (va == '+');
            matrixI[j][i] = (va == '+');
        }
    }
    for(int k = 0; k < n;++k){
        for(int i = k+1; i < n;++i){
            if(i == k)continue;
            for(int j = i+1; j < n;++j){
                if(j == k) continue;
                if(matrixN[k][i] && matrixI[k][j] && matrixN[i][j]){
                    vector<pi> yei = {{k,i},{i,j},{j,k}};
                    sort(yei.begin(),yei.end());
                    string ha = "";
                    for(auto va:yei)
                        ha += "+" + to_string(va.first) + "," + to_string(va.second);
                    wut.insert(ha);
                }
            }
        }
    }
    printf("%d\n",(int)wut.size());
    return 0;
}
