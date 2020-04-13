#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    scanf(" %d %d",&n,&k);
    char ar[n+1];
    scanf(" %s",ar);
    if(k > n){puts("WRONGANSWER");return 0;}
    char ans[n+1];
    ans[n] = '\0';
    set<char> uni;
    for(int i = 0; i < 26;++i) uni.insert(i+'a');
    for(int i = 0; i < n;++i)
        uni.erase(ar[i]);
    for(int i = 0, j = n-k; i < k;++i,++j)
        ans[i] = ar[j];
    if(k == 0 && uni.size()){
        for(int i = 0; i < n;++i)
            printf("%c",(*uni.begin()));
        return 0;
    }
    else if(k == 0){puts("WRONGANSWER");return 0;}
    char add = 'z';
    while(add == ar[n-1]) --add;
    for(int i = k; i < n;++i)
        ans[i] = add;
    printf("%s\n",ans);
    return 0;
}
