#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        for(int i = 0; i < n;++i){
            int temp; scanf(" %d",&temp);
            temp = abs(temp);
            if(i&1) printf("%d ",temp);
            else printf("%d ",-temp);
        }
        puts("");
    }
    return 0;
}
