#include<bits/stdc++.h>
using namespace std;

int UF[800];
int rk[800];
typedef pair<int,int> pi;

int search(int x){
    return x == UF[x] ? x: (UF[x] = search(UF[x]));
}

bool connected(int x, int y){
    return search(x) == search(y);
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
    while(scanf(" %d",&n) == 1){
        for(int i = 0; i < 800;++i)
            UF[i] = i,rk[i] = 1;
        pi nums[n];
        for(int i = 0; i < n;++i)
            scanf(" %d %d",&nums[i].first,&nums[i].second);
        scanf(" %d",&m);
        while(m--){
            int a,b;
            scanf(" %d %d",&a,&b);
            --a,--b;
            connect(a,b);
        }
        priority_queue<pair<int,pi>> q;
        for(int i = 0; i < n;++i){
            for(int j = i+1; j < n;++j){
                int dif1 = (nums[i].first - nums[j].first)*(nums[i].first - nums[j].first);
                int dif2 = (nums[i].second - nums[j].second)*(nums[i].second - nums[j].second);
                q.push({-(dif1+dif2),{i,j}});
            }
        }
        double ans = 0.0;
        while(q.size()){
            int f1 = -q.top().first; pi f2= q.top().second;
            q.pop();
            if(connected(f2.first,f2.second)) continue;
            ans += (double)sqrt((double)f1);
            connect(f2.first,f2.second);
        }
        printf("%.2f\n",ans);
    }
    return 0;
}
