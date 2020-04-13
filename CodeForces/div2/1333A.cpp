#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,m;
        scanf(" %d %d",&n,&m);
        for(int i = 0; i < n;++i){
            for(int j = 0; j < m-1;++j)
                printf("B");
            if(i!= n-1) printf("W\n");
            else printf("B\n");
        }
    }
    return 0;
}
