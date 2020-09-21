#include<bits/stdc++.h>
using namespace std;

char possi[] = {'1','0'};

int main(){
    int n,p;
    scanf(" %d %d",&n,&p);
    vector<vector<char>> classes(p);
    for(int i = 0; i < n;++i){
        char va;
        scanf(" %c",&va);
        classes[i%p].push_back(va);
    }
    //cout << "here?\n";
    bool ans = 0;
    for(int i = 0; i < p;++i){
        set<char> seen;
        int rep = 0;
        for(auto va:classes[i]){
            seen.insert(va);
            if(va == possi[rep])
                ++rep;
            rep = rep&1;
        }
        for(auto &va:classes[i])
            if(va == '.')
                va = possi[rep];
        if((int)seen.size() == 1 && (*seen.begin()) == '.')
            classes[i][classes[i].size()-1] = possi[(rep+1)&1];
        if((int)seen.size() > 1 || ((int)classes[i].size() > 1 && *seen.begin() == '.'))
            ans = 1;
    }
    if(!ans){puts("No");return 0;}
    char show[n];
    for(int i = 0; i < classes.size();++i){
        for(int j = 0; j < classes[i].size();++j)
            show[i+(j*p)] = classes[i][j];
    }
    for(int i = 0; i < n;++i)
        printf("%c",show[i]);
    puts("");
    return 0;
}
