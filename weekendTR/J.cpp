#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll nums[505][505];
ll caminos[505][505];
ll answer[505][505];

int main(){
    int n;
    scanf(" %d",&n);
    char val[n+1];
    for(int i = 0; i < n;++i){
        scanf(" %s",val);
        for(int j = 0; j < n;++j)
            nums[i][j] = (val[j]-'0');
    }
    for(int i = 0; i < n-1;++i)
        if(nums[i][i+1])
            answer[i][i+1] = caminos[i][i+1] = 1;
    for(int d = 2; d < n;++d){
        for(int i = n-1; i > -1;--i){
            if(i+d >= n)continue;
            ll sum = 0;
            for(int j = i+1; j < i+d;++j){
                if(answer[i][j] == 1)
                    sum += caminos[j][i+d];
                if(sum >= 10) sum -= 10;
            }
            if(nums[i][i+d] != sum%10ll){
                answer[i][i+d] = 1;
                ++sum;
            }
            caminos[i][i+d] = sum;
        }
    }
    for(int i = 0; i < n;++i){
        for(int j = 0; j < n;++j)
            printf("%lld",answer[i][j]);
        printf("\n");
    }
    return 0;
}
