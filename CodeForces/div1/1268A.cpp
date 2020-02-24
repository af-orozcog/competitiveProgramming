#include<bits/stdc++.h>
using namespace std;

int eq[200009];
char nums[200009];
int main(){
    int n,k;
    scanf(" %d %d",&n,&k);
    for(int i = 0; i < n;++i) scanf(" %c",&nums[i]);
    bool keep = 1;
    for(int i = k-1; i > -1 && keep;--i){
        if(i + k < n && (nums[i+k]-'0') <= (nums[i]-'0'))
            keep = 0;
    }
    if(keep)
        nums[k-1] = nums[k-1]+1;
    printf("%d\n",n);
    for(int i = 0; i < n;++i)
        printf("%c",nums[i%k]);
    puts("");
    return 0;
}
