#include<bits/stdc++.h>
using namespace std;

char see[204];
char show[204];

int main(){
    int t;
    while(scanf(" %d",&t) && t){
        scanf(" %s",see);
        int siz = strlen(see);
        int rows = siz/t;
        int j = 0;
        for(int i = 0; i < rows;){
            for(int k = 0; k < t;++k)
                show[rows*k+i] = see[j++];
            ++i;
            for(int k = t-1; k > -1 && i < rows;--k)
                show[rows*k+i] = see[j++];
            ++i;
        }
        show[siz] = '\0';
        printf("%s\n",show);
    }
    return 0;
}
