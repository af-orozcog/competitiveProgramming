#include<bits/stdc++.h>
using namespace std;


int inversions(string &check){
    int a = 0;
    int ans = 0;
    for(auto it = check.rbegin(); it != check.rend();++it){
        if((*it) == 'a') ++a;
        else ans += a;
    }
    return ans;
}

void add(string val, vector<vector<string>> &ans){
    do{
        int see = inversions(val);
        ans[see].push_back(val);
    }while(next_permutation(val.begin(),val.end()));
}


vector<vector<string>> difference(int n){
    vector<vector<string>> answer(300);
    string see = "";
    for(int i = 0; i < n;++i)
        see += 'a';
    add(see,answer);
    for(int i = n-1;i > -1;--i){
        see[i] = 'b';
        add(see,answer);
    }
    return answer;
}

int main(){
    for(int i = 1; i < 10;++i){
        vector<vector<string>> use = difference(i);
        for(int j = 0; j < use.size();++j){
            sort(use[j].begin(),use[j].end());
            int tama = use[j].size();
            if(tama == 0) break;
            cout <<"tamano " << i <<" " <<"inversions: " << j << "\n";
            if(tama%2 == 0)
                cout << use[j][tama/2 -1]<<"\n";
            cout << use[j][tama/2] << "\n";
            cout <<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" <<"\n";
        }
    }
    return 0;
}
