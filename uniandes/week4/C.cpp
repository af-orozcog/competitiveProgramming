#include<bits/stdc++.h>
using namespace std;

bool triangle(){

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
}
