#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        int n;
        scanf(" %d",&n);
        int matrix[n][n];
        memset(matrix,0,sizeof(matrix));
        pair<char,char> nums[n];
        for(int i = 0; i < n;++i)
            scanf(" %c",&nums[i].first);
        for(int i = 0; i < n;++i)
            scanf(" %c",&nums[i].second);
        matrix[0][0] = 1;
        for(int i = 1; i < n;++i){
            if(nums[i-1].second == 'Y' && nums[i].first == 'Y')
                matrix[i-1][i] = 1;
            if(nums[i-1].first == 'Y' && nums[i].second == 'Y')
                matrix[i][i-1] = 1;
            matrix[i][i] = 1;
        }
        for(int k = 0; k < n;++k)
            for(int i = 0; i < n;++i)
                for(int j = 0; j < n;++j)
                    matrix[i][j] = (matrix[i][j] | (matrix[i][k] && matrix[k][j]));
        printf("Case #%d:\n",cas++);
        for(int i = 0; i < n;++i){
            for(int j = 0; j < n;++j)
                printf("%c",(matrix[i][j] == 1?'Y':'N'));
            puts("");
        }
    }
    return 0;
}
