#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

int main(){
    int n;
    scanf(" %d",&n);
    vector<int> answer(n<<1,-1);
    priority_queue<pair<int,pi>> q;
    for(int i = 1; i < (n<<1);++i){
        for(int j = 0; j < i;++j){
            int va;
            scanf(" %d",&va);
            q.push({va,{i+1,j+1}});
        }
    }
    while(q.size()){
        int fi = q.top().second.first;
        int se = q.top().second.second;
        q.pop();
        if(answer[fi-1] != -1 || answer[se-1] != -1) continue;
        answer[fi-1] = se;
        answer[se-1] = fi;
    }
    for(auto va:answer)
        printf("%d ",va);
    puts("");
    return 0;
}
