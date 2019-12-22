#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int fr[101]; memset(fr,0,sizeof(fr));
        int ar[n];
        int ma = 0,po;
        for(int i = 0; i < n;++i){
            int va;scanf(" %d",&va);
            ++fr[va];
            ar[i] = va;
            if(fr[va] > ma){
                ma = fr[va]; po = i;
            }
        }
        vector<bool> marked(n,false);
        queue<int> q;
        q.push(po);
        int ans = 0;
        while(q.size()){
            int f = q.front();q.pop();
            marked[f] = 1;
           // cout << ar[f] << " " << ar[po] << endl;
            if(ar[f] != ar[po]) ++ans;
            if(f > 0 && !marked[f-1]) q.push(f-1);
            if(f < n-1 && !marked[f+1]) q.push(f+1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
