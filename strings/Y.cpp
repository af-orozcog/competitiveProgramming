#include<bits/stdc++.h>

using namespace std;

struct node{
    int q = 0;
    map<char,node> child;
};

node root;

void insert(string &re){
    node act = root;
    ++act.q;
    for(int i = 0; i < re.size();++i){
        ++act.q;
        if(act.child.count(re[i]))
            act = act.child[re[i]];
        else{
            node add;
            act.child[re[i]] = add;
            act = act.child[re[i]];
        }
    }
}

int fin(string &re){
    int ans = 0;
    node act = root;
    for(int i = 0; i < re.size();++i){
        if(!act.child.count(re[i])) break;
        act = act.child[re[i]];
        int temp = act.q;
        if(i == re.size()-1) ans = temp;
    }
    return ans;
}

int del(string &re){
    node act = root;
    --act.q;
    for(int i = 0; i < re.size();++i){
        --act.q;
        act = act.child[re[i]];
    }
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int q;string ri;
        cin >> q >> ri;
        if(q == 1)
            insert(ri);
        else if(q == 2)
            del(ri);
        else
            cout << fin(ri) << endl << flush;
    }
    return 0;
}
