#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> lookFor(string &see, int tama){
    vector<int> kmp(see.size(),0);
    vector<ll> ans(see.size(),0);
    int border = 0;
    for(int i = 1; i < see.size();++i){
        while(border && see[i] != see[border])
            border = kmp[border-1];
        if(see[i] == see[border])
            ++border;
        if(border == tama)
            ++ans[i-tama+1];
        kmp[i] = border;
    }
    return ans;
}

int main(){
    string see,part1,part2;
    cin >> see >> part1 >> part2;
    string send1 = part1 + "$"+ see;
    string send2 = part2 + "$" + see;
    vector<ll> use1 = lookFor(send1,part1.size());
    vector<ll> use2 = lookFor(send2,part2.size());
    for(int i = use2.size()-1; i > -1;--i){
        if(use2[i]){
            use2[i] = 0;
            use2[i+(int)part2.size()-1] = 1;
        }
    }
    unordered_set<string> ans;
    for(int i = part1.size()+1,j = part2.size()+1; i < use1.size();++i,++j){
        if(use1[i]){
            string temp = "";
            for(int k = i, q = j; k < use1.size();++k,++q){
                temp += send1[k];
                if(use2[q] && temp.size() >= max(part1.size(),part2.size())) ans.insert(temp);
            }
        }
    }
    printf("%d\n",(int)ans.size());
    return 0;
}
