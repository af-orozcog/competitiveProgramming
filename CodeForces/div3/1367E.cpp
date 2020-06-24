#include<bits/stdc++.h>
using namespace std;

bool check(map<char,int> tr, int siz,int k){
    map<int,int> tama;
    for(auto va:tr)
        tama[va.second]++;
    vector<int> marked(siz,0);
    vector<int> moved(siz);
    for(int i = 0; i < siz;++i)
        moved[(i+k)%siz] = i;
    for(int i = 0; i < siz;++i){
        if(moved[i] == i)
            return 1;
    }
    vector<int> cycle;
    for(int i = 0;i < siz;++i){
        int wut = 0;
        int j = i;
        while(!marked[j]){
            marked[j] = 1;
            ++wut;
            j = moved[j];
        }
        if(wut != 0) cycle.push_back(wut);
    }
    sort(cycle.begin(),cycle.end());
    for(int i = 0; i < cycle.size();++i){
        int val = -1;
        for(auto va:tama){
            if(va.first >= cycle[i]){val = va.first;break;}
        }
        if(val == -1)return 0;
        tama[val]--;
        if(!tama[val])
            tama.erase(val);
        val -= cycle[i];
        if(val)
            ++tama[val];
    }
    return 1;
}


int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,k;
        scanf(" %d %d",&n,&k);
        map<char,int> tr;
        for(int i = 0; i < n;++i){
            char va; scanf(" %c",&va);
            ++tr[va];
        }
        int lo = 1, hi = n,ans = 1;
        while(lo <= hi){
            int mid = (lo+hi)>>1;
            if(check(tr,mid,k))
                lo = mid + 1, ans = mid;
            else
                hi = mid -1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
