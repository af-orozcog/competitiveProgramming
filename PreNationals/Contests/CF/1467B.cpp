#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int t;
    scanf(" %d",&t);
    int co = 0;
    while(t--){
        ++co;
        int n;
        scanf(" %d",&n);
        int marked[n],nums[n];
        for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
        memset(marked,0,sizeof(marked));
        if(co == 23){
            for(auto va:nums)
                cout << va << "-";
            cout << "\n";
        }
        int ans = 0;
        for(int i = 1; i < n-1;++i){
            if(nums[i] > nums[i+1] && nums[i] > nums[i-1]){++ans,marked[i] = 1;}
            else if(nums[i] < nums[i+1] && nums[i] < nums[i-1]){++ans,marked[i] = -1;}
        }
        int les = 0;
        for(int i = 0; i < n && n > 2;++i){
            if(i == 0){
                if(marked[i+1]) les = 1;
            }
            else if(i == n-1){
                if(marked[i-1]) les = max(les,1);
            }
            else{
                int posi1 = nums[i-1],posi2 = nums[i+1];
                int temp1,temp2;
                temp1 = temp2 = (marked[i] != 0);
                if(marked[i-1]) ++temp1;
                if(marked[i+1]) ++temp2;
                if((posi1 <= posi2 && marked[i+1] == -1) || (posi1 >= posi2 && marked[i+1] == 1)) ++temp1;
                if((posi2 >= posi1 && marked[i-1] == 1) || (posi2 <= posi1 && marked[i-1] == -1)) ++temp2;
                les = max(les,max(temp1,temp2));
            }
        }
        printf("%d\n",ans-les);
    }
    return 0;
}
