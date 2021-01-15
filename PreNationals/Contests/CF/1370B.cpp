#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        vector<int> even,odd;
        for(int i = 0; i < n*2;++i){
            int va;
            scanf(" %d",&va);
            if(va&1) odd.push_back(i);
            else even.push_back(i);
        }
        if((int)odd.size()&1){
            odd.pop_back();
            even.pop_back();
        }
        else{
            if(odd.size()){
                odd.pop_back();
                odd.pop_back();
            }
            else{
                even.pop_back();
                even.pop_back();
            }
        }
        for(int i = 0; i < odd.size();i+=2)
            printf("%d %d\n",odd[i]+1,odd[i+1]+1);
        for(int i = 0;i < even.size();i+=2)
            printf("%d %d\n",even[i]+1,even[i+1]+1);

    }
    return 0;
}
