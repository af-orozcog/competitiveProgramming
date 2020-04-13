#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        set<int> seen;
        int A[n],B[n];
        for(int i = 0; i < n;++i) scanf(" %d",&A[i]);
        for(int i = 0; i < n;++i) scanf(" %d",&B[i]);
        bool posi = 1;
        for(int i = 0; i < n && posi;++i){
            if(B[i] > A[i] && !seen.count(1))posi = 0;
            else if(B[i] < A[i] && !seen.count(-1)) posi = 0;
            seen.insert(A[i]);
        }
        if(posi) puts("YES");
        else puts("NO");
    }
    return 0;
}
