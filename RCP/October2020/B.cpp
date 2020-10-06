#include<bits/stdc++.h>
using namespace std;

int count(int number,int dig){
    int ans = 0;
    while(number){
        if(number%10 == dig)++ans;
        number /= 10;
    }
    return ans;
}

int main(){
    int a,b,dig;
    scanf(" %d %d %d",&a,&b,&dig);
    int ans = 0;
    for(int i = a; i <= b;++i)
        ans += count(i,dig);
    printf("%d\n",ans);
    return 0;
}
