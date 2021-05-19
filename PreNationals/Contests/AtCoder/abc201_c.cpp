#include<bits/stdc++.h>
using namespace std;

char use[11];
int needed = 0;

bool check(vector<char> &now){
    vector<bool> co(10,0);
    for(auto va:now)
        co[va-'0'] = 1;
    for(int i = 0; i < 10;++i){
        if(co[i] && use[i] == 'x') return 0;
        else if(!co[i] && use[i] == 'o') return 0;
    }
    return true;
}

int ways(vector<char> &now){
    if(now.size() == 4)
        return check(now);
    int ans = 0;
    for(int i = 0; i < 10;++i){
        if(i) now.pop_back();
        now.push_back('0'+(char)i);
        ans += ways(now);
    }
    now.pop_back();
    return ans;
}


int main(){
    scanf(" %s",use);
    for(int i = 0; i < 10;++i)
        needed += (use[i] == 'o');
    vector<char> now;
    printf("%d\n",ways(now));
    return 0;
}
