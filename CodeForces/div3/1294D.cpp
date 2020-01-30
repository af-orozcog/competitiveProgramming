#include<bits/stdc++.h>
using namespace std;

int vals[4*100001];

int main(){
    int q,a;
    set<int> ava;
    for(int i = 0; i < 4*100001;++i) ava.insert(i);
    scanf(" %d %d",&q,&a);
    while(q--){
        int val;scanf(" %d",&val);
        val = val%a;
        ava.erase(val+(vals[val]*a));
        ++vals[val];
        printf("%d\n",(*ava.begin()));
    }
    return 0;
}
