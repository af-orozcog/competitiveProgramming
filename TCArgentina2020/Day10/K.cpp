#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    vector<int> important;
    for(int i = 0; i < n;++i){
        int c,t;
        scanf(" %d %d",&c,&t);
        if(important.size())
            important.push_back(important.back()+c*t);
        else
            important.push_back(c*t);
    }
    for(int i = 0; i < m;++i){
        int v;
        scanf(" %d",&v);
        int ind = lower_bound(important.begin(),important.end(),v)-important.begin();
        ++ind;
        printf("%d\n",ind);
    }
    return 0;
}
