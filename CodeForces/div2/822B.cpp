#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    char s[n],t[m];
    scanf(" %s %s",s,t);
    vector<int> ans;
    int bi = 100000;
    for(int i = 0; i <= m-n;++i){
        vector<int> temp;
        for(int j = i,k = 0; k < n;++k,++j){
            if(s[k] != t[j]) temp.push_back(k);
        }
       // cout << temp.size() << endl;
        if((int)temp.size() < bi){
            bi = temp.size();
            ans = temp;
        }
    }
    printf("%d\n",bi);
    for(auto va:ans) printf("%d ",va+1);
    puts("");
    return 0;
}
