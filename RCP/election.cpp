#include<bits/stdc++.h>
using namespace std;

int main(){
    int w,p;
    scanf(" %d %d",&w,&p);
    int go = (w>>1)+1;
    int co = 0;
    vector<int> posi;
    for(int i = 0; i < w;++i){
        int me;scanf(" %d",&me);
        map<int,int> fr;
        for(int j = 1; j < p;++j){
            int va;scanf(" %d",&va);
            ++fr[va];
        }
        int tot = 0;
        while(me <= q.top()){
            int dist = (q.top() - me)>>1;
            me += dist + 1;
            tot += dist + 1;
            q.pop();
        }
        cout << tot << endl;
        posi.push_back(tot);
    }
    sort(posi.begin(),posi.end());
    int i = 0;
    int ans = 0;
    while(co < go){
        ans += posi[i];
        ++i;
        ++co;
    }
    printf("%d\n",ans);
    return 0;
}
