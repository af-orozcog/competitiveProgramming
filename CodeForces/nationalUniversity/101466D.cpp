#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    int co = 0;
    vector<char> ans;
    while(n){
        if(n&1){
            --n; n = n >>1;
            ans.push_back('A');
        }
        else{
            n -= 2;
            n = n >>1;
            ans.push_back('B');
        }
    }
    for(int i = ans.size()-1;i > -1;--i) printf("%c",ans[i]);
    puts("");
    return 0;
}
