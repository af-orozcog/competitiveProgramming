#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000002;

int UF[MAXN];
int rk[MAXN];

int search(int x){
    return UF[x] == x ? x:(UF[x] = search(UF[x]));
}

void connect(int x, int y){
    int dadX = search(x), dadY = search(y);
    if(dadX != dadY){
        if(rk[dadX] > rk[dadY])
            UF[dadY] = dadX;
        else{
            UF[dadX] = dadY;
            if(rk[dadX] == rk[dadY]) ++rk[dadY];
        }
    }
}

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    int nums[n];
    for(int i = 0; i < n;++i){
        UF[i] = i;
        rk[i] = 1;
    }
    for(int i = 0; i < n;++i)
        scanf(" %d",&nums[i]);
    for(int i = 0; i < m;++i){
        int a,b;
        scanf(" %d %d",&a,&b);
        --a,--b;
        connect(a,b);
    }
    map<int,int> tr;
    vector<vector<int>> see;
    for(int i = 0; i < n;++i){
        //cout << search(i) << "\n";
        if(tr.count(search(i)))
            see[tr[search(i)]].push_back(nums[i]);
        else{
            vector<int> add;
            tr[search(i)] = see.size();
            add.push_back(nums[i]);
            see.push_back(add);
        }
    }
    for(auto &ve:see)
        sort(ve.begin(),ve.end());
    for(int i = 0; i < n;++i){
        printf("%d ",see[tr[search(i)]].back());
        see[tr[search(i)]].pop_back();
    }
    puts("");
    return 0;
}
