#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,d;
        scanf(" %d %d",&n,&d);
        int but[n];
        for(int i = 0; i < n;++i)scanf(" %d",&but[i]);
        int dp[3606];
        memset(dp,-1,sizeof(dp));
        dp[0] = 0;
        bool keep = 1;
        queue<int> q;
        q.push(0);
        while(q.size()){
            int f = q.front();
            q.pop();
            for(int i = 0; i < n;++i){
                int get;
                if(f+but[i] >= 3600) get = 3600;
                else if(f+but[i] < 0) get = 0;
                else get = f + but[i];
                //if(get == 50) cout << "lil" << endl;
                if(dp[get] == -1){
                    dp[get] = dp[f] + 1;
                    q.push(get);
                }
            }
        }
        //cout << "wut" << "\n";
        int ans1;
        int ans2;
        for(int i = d,j = 0;;++i,++j){
            if(dp[i] != -1){
                ans1 = dp[i];
                ans2 = j;
                break;
            }
        }
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
