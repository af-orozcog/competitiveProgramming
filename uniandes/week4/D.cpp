#include<bits/stdc++.h>
using namespace std;

bool triangle(vector<int> check){
    if(check[0] + check[1] <= check[2]) return 0;
    if(check[0] + check[2] <= check[1]) return 0;
    if(check[1] + check[2] <= check[0]) return 0;
    return 1;
}

bool degenerate(vector<int> check){
    sort(check.begin(),check.end());
    return check[0] + check[1] == check[2];
}

int main(){
    vector<int> nums(4);
    int sum = 0;
    for(int i = 0; i < 4;++i){
        scanf(" %d",&nums[i]);
        sum += nums[i];
    }
    bool tri = 0;
    bool dege = 0;
    for(int i = 0; i < 4;++i){
        for(int j = i+1; j < 4;++j){
            for(int k = j+1; k < 4;++k){
                vector<int> send = {nums[i],nums[j],nums[k]};
                if(triangle(send)) tri = 1;
                if(degenerate(send)) dege = 1;
            }
        }
    }
    if(tri) puts("TRIANGLE");
    else if(dege) puts("SEGMENT");
    else puts("IMPOSSIBLE");
    return 0;
}
