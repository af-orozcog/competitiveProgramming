#include<bits/stdc++.h>
using namespace std;

int marked[3][3];
int nums[3][3];

void mark(int num){
    for(int i = 0; i < 3;++i){
        for(int j = 0; j < 3;++j)
            marked[i][j] = (marked[i][j])| (nums[i][j] == num);
    }
}

int main(){
    for(int i = 0; i < 3;++i){
        for(int j = 0; j < 3;++j)
            scanf(" %d",&nums[i][j]);
    }
    int n; scanf(" %d",&n);
    while(n--){
        int a;scanf(" %d",&a);
        mark(a);
    }
    bool yes = 0;
    for(int i = 0; i < 3 && !yes;++i){
        int sum = 0;
        for(int j = 0; j < 3;++j)
            sum += marked[i][j];
        yes = (sum== 3);
    }
    for(int j = 0; j < 3 && !yes;++j){
        int sum = 0;
        for(int i = 0; i < 3;++i)
            sum += marked[i][j];
        yes = (sum== 3);
    }
    int sum = 0;
    for(int i = 0; i < 3 && !yes;++i) sum+= marked[i][i];
    yes = yes | (sum == 3);
    sum = 0;
    for(int i = 0,j = 2; i < 3 && !yes;++i,--j) sum+= marked[i][j];
    yes = yes | (sum == 3);
    if(yes) puts("Yes");
    else puts("No");
}
