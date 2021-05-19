#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    char vals[] = {'(',')'};
    while(t--){
        int n;
        scanf(" %d",&n);
        char a[n+1];
        scanf(" %s",a);
        int co[2];
        memset(co,0,sizeof(co));
        for(int i = 0; i < n;++i)
            ++co[a[i]-'0'];
        if(a[0] != a[n-1] || a[0] != '1' || co[0] % 2 || co[1] % 2){puts("NO");continue;}
        char ans1[n+1],ans2[n+1];
        ans1[n] = ans2[n] = '\0';
        co[1] /= 2;
        for(int i = 0, next = 0; i < n;++i){
            if(a[i] == '0'){
                ans1[i] = vals[next];
                ans2[i] = vals[(next+1)%2];
                next = (next+1)%2;
            }
            else if(co[1]){
                ans1[i] = ans2[i] ='(';
                --co[1];
            }
            else ans1[i] = ans2[i] = ')';
        }
        printf("YES\n%s\n%s\n",ans1,ans2);
    }
    return 0;
}
