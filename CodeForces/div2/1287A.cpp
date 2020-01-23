#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        vector<int> po;
        for(int i = 0; i < n;++i){
            char see;
            scanf(" %c",&see);
            if(see == 'A') po.push_back(i);
        }
        po.push_back(n);
        int ma = 0;
        for(int i = po.size()-2;i > -1;--i)
            ma = max(po[i+1]-po[i]-1,ma);
        printf("%d\n",ma);
    }
    return 0;
}
