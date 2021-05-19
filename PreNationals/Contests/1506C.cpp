#include<bits/stdc++.h>
using namespace std;

bool found(string &see, int sz){
    vector<int> kmp(see.size(),0);
    int border = 0;
    for(int i = 1; i < see.size();++i){
        while(border && see[border] != see[i])
            border = kmp[border-1];
        if(see[border] == see[i])
            ++border;
        kmp[i] = border;
        if(border == sz) return true;
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        if(a.size() > b.size())
            swap(a,b);
        int ans = (int)a.size() + (int)b.size();
        for(int i = 0; i < a.size();++i){
            for(int j = i; j < b.size();++j){
                int take = j-i+1;
                string lol = a.substr(i,take);
                string send = lol + "@" + b;
                if(found(send,lol.size())){
                    int val = a.size()-lol.size() + b.size() - lol.size();
                    ans = min(ans,val);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
