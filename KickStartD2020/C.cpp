#include<bits/stdc++.h>
using namespace std;

int nums[100000];
int marked[100000];

int counted(int start,int it, int hops){
    int co = 0;
    int ans = 0;
    while(start != 1){
        if(co == 0 && marked[start] != it)
            ++ans,marked[start] = it;
        ++co;
        start = nums[start];
        co = co % hops;
    }
    if(start == 1 && co == 0 && marked[start] != it)
        ++ans;
    return ans;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,a,b;
        scanf(" %d %d %d",&n,&a,&b);
        for(int i = 2; i <= n;++i){
            scanf(" %d",&nums[i]);
        }
        double divided = (double)n*(double)n;
        double sum = 0.0;
        for(int i = 1, it = 0; i <= n;++i){
            for(int j = 1; j <= n;++j,++it){
                sum += (double)counted(i,it,a);
                sum += (double)counted(j,it,b);
            }
        }
        cout << setprecision(7) << sum/divided << "\n";
    }
    return 0;
}
