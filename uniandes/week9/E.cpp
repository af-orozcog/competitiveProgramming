#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int> possible;
    for(int i = 3;i < 600;++i){
        int sup = (i-2)*180;
        if(sup % i == 0 && sup/i <= 180)
            possible.insert(sup/i);
    }
    int t;
    scanf(" %d",&t);
    while(t--){
        int check;
        scanf(" %d",&check);
        if(possible.count(check))
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
