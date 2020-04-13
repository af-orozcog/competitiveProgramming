#include<bits/stdc++.h>
using namespace std;

int nums[200000];
int ar[3];
int posi = 1;
void dfs(int dad1, int dad2, int p, vector<vector<int>> &graph){
    if(!posi) return;
    if(dad1!=-1){
        int me = 3-nums[dad1];
        if(me == 3){
            if(ar[1] >= ar[2] && ar[1]){
                nums[p] = 1; --ar[1];
            }
            else if(ar[2] >= ar[1] && ar[2]){
                nums[p] = 2; --ar[2];
            }
            else if(ar[0]){
                nums[p] = 0,--ar[0];
            }
            else posi = 0;
        }
        else{
            if(ar[me]){nums[p] = me,--ar[me];}
            else if(ar[0]){nums[p] = 0,--ar[0];}
            else posi = 0;
        }
    }
    else{
        if(ar[1] >= ar[2] && ar[1]){
                nums[p] = 1; --ar[1];
        }
        else if(ar[2] >= ar[1] && ar[2]){
            nums[p] = 2; --ar[2];
        }
        else{
            nums[p] = 0;--ar[0];
        }
    }
    for(int i = 0; i < graph[p].size();++i)
        if(graph[p][i] != dad2)
            dfs(dad2,p,graph[p][i],graph);
}

int main(){
    int n;
    scanf(" %d",&n);
    for(int i = 1; i<= n;++i) ++ar[i%3];
    vector<vector<int>> graph(n);
    for(int i = 0; i < n-1;++i){
        int a,b;
        scanf(" %d %d",&a,&b);
        --a,--b;
        graph[b].push_back(a);
        graph[a].push_back(b);
    }
    dfs(-1,-1,0,graph);
    if(!posi) puts("-1");
    else{
        int temp[] = {1,0,0};
        for(int i = 0; i < n;++i){
            printf("%d ",temp[nums[i]]*3 +nums[i]);
            ++temp[nums[i]];
        }
        puts("");
    }
    return 0;
}
