#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    scanf(" %d %d",&n,&k);
    unordered_map<string,int> st;
    string vals[n];
    for(int i= 0; i < n;++i) cin >> vals[i],st[vals[i]] = i;
    int ans = 0;
    set<pair<int,pair<int,int>>> uni;
    for(int i = 0; i < n;++i){
        for(int j = i+1; j < n;++j){
            string look = "";
            //cout << "before " << look << endl;
            for(int l = 0; l < k;++l){
                if(vals[i][l] == vals[j][l]) look += vals[i][l];
                else if(vals[i][l] == 'S' && vals[j][l] == 'T') look += 'E';
                else if(vals[i][l] == 'T' && vals[j][l] == 'S') look += 'E';
                else if(vals[i][l] == 'E' && vals[j][l] == 'T') look += 'S';
                else if(vals[i][l] == 'T' && vals[j][l] == 'E') look += 'S';
                else if(vals[i][l] == 'E' && vals[j][l] == 'S') look += 'T';
                else look += 'T';
            }
            //cout << look << endl;
            if(st.count(look)){
                int temp[3];
                temp[0] = i,temp[1] = j,temp[2] = st[look];
                sort(temp,temp+3);
                uni.insert({temp[0],{temp[1],temp[2]}});
            }
        }
    }
    printf("%d\n",(int)uni.size());
    return 0;
}
