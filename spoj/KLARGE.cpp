#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1000010;

int BIT[MAXN];

int LN = -1;

void update(int pos){
    while(pos < MAXN){
       // printf("%d\n",pos);
        ++BIT[pos];
        int i = pos&(-pos);
        pos += i;
    }
}

int kth(int va){
    int sum = 0;
    int pos = 0;
    for(int i = LN; i > -1;--i){
        //printf("%d\n",pos + (1<<i));
        if(pos + (1 << i) <  MAXN && sum+BIT[pos + (1<<i)] < va){
            sum += BIT[pos + (1<<i)];
            pos += (1 << i);
        }
    }
    return pos;
}

int main(){
    int temp = MAXN;
    while(temp){
        ++LN;
        temp >>= 1;
    }
    int t;
    scanf(" %d",&t);
    while(t--){
        memset(BIT,0,sizeof(BIT));
        int n;
        scanf(" %d",&n);
       // printf("%d\n",n);
        for(int i = 0; i < n;++i){
            int temp;
            scanf(" %d",&temp);
            ++temp;
            update(temp);
        }
        //printf("%d\n%d\n",BIT[2],BIT[3]);
        int k;scanf(" %d",&k);
        printf("%d\n",kth(n-k+1));
    }
    return 0;
}
