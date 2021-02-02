#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_set<int> seen;
    int ans = 0;
    int temp;
    while(scanf("%d",&temp) == 1){
        int look = 2020-temp;
        if(seen.count(look))
            ans = temp*look;
        seen.insert(temp);
    }
    printf("%d\n",ans);
}
