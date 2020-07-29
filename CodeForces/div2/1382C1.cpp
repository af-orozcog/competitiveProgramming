#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int a[n];
        int b[n];
        for(int i = 0; i < n;++i){
            char temp;
            scanf(" %c",&temp);
            a[i] = (temp == '1');
        }
        for(int i = 0; i < n;++i){
            char temp;
            scanf(" %c",&temp);
            b[i] = (temp == '1');
        }
        int start[2] = {0,n-1};
        int add[2] = {1,-1};
        int lel = 0;
        vector<int> operations;
        int j = n-1;
        while(start[0] != start[1]){
            if(b[j] == (a[start[1]]+(lel%2))%2)
                start[1] += add[1];
            else{
                if(b[j] == (a[start[0]]+(lel%2))%2)
                    operations.push_back(1);
                operations.push_back(j+1);
                start[0] += add[0];
                swap(start[1],start[0]);
                swap(add[0],add[1]);
                ++lel;
            }
            --j;
        }
        if(b[j] != (a[start[1]]+(lel%2))%2)
            operations.push_back(1);
        printf("%d",(int)operations.size());
        for(auto va:operations)
            printf(" %d",va);
        puts("");
    }
    return 0;
}
