#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int N,F,T;
    int cas = 1;
    while(1){
        scanf(" %d %d %d",&N,&F,&T);
        if(N == F && F == T && T == 0) break;
        vector<vector<pair<int,int>>> graph(N*N);
        for(int i = 0; i < N;++i){
            for(int j = 0; j < N;++j){
                int va; scanf(" %d",&va);
                int me = i*N + j;
                if(j -1 > -1) graph[me].push_back({me-1,va});
                if(j +1 < N) graph[me].push_back({me+1,va});
                if(me - N > -1) graph[me].push_back({me-N,va});
                if(me + N < N*N) graph[me].push_back({me+N,va});
            }
        }
        vector<vector<ll>> comp(F,vector<ll> (N*N,1000000000));
        for(int i = 0; i < F;++i){
            int x,y; scanf(" %d %d",&x,&y);
            int me = x*N + y;
            //cout << me << endl;
            comp[i][me] = 0;
           // cout << graph[me].size() << endl;
            vector<ll> temp(N*N,1000000000);
            for(int j = 0; j < T;++j){
                for(int k = 0; k < graph.size();++k){
                    for(int z = 0;z < graph[k].size();++z){
                        temp[graph[k][z].first] = min(comp[i][graph[k][z].first],temp[graph[k][z].first]);
                        temp[graph[k][z].first] = min(temp[graph[k][z].first],comp[i][k] + (ll)graph[k][z].second);
                        //cout <<"whats with temp " <<temp[graph[k][z].first] <<" " <<graph[k][z].first<< endl;
                    }
                }
                comp[i] = temp;
                //for(auto va: temp) cout << va <<" ";
                //cout << "\n";
                temp.assign(N*N,1000000000);
            }
        }

        ll ans = 1000000000, vaX,vaY;
        for(int i = 0; i < N*N;++i){
            ll sum = 0;
            for(int j = 0; j < F;++j)
                sum += comp[j][i];
            //cout << sum <<" city is " << i<<endl;
            int meX = i / N, meY = i % N;
            if(sum < ans){
               // cout << sum << " " << meX << " " << meY << endl;
                ans = sum,vaX = meX,vaY = meY;
             //   cout << "what ?" << ans << endl;
            }
            else if(sum == ans){
                if(meX < vaX) vaX = meX,vaY = meY;
                else if(meX == vaX && meY < vaY) vaX = meX,vaY = meY;
            }
           // cout << vaX<< " "<< vaY<< " "<<ans<<endl;
        }
        if(ans != 1000000000)
            printf("Case #%d: Selected city (%lld,%lld) with minimum cost %lld.\n",cas++,vaX,vaY,ans);
        else printf("Case #%d: Impossible.\n",cas++);
    }
    return 0;
}
