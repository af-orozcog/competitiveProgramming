#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    vector<int> ans;
    int i = 1;
    while(n){
        if(n < i){
            ans.back() += n;
            n = 0;
        }
        else{
            ans.push_back(i);
            n -= i;
        }
        ++i;
    }
    printf("%d\n",ans.size());
    for(auto va:ans)
        printf("%d ",va);
    puts("");
    return 0;
}
