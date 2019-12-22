#include<bits/stdc++.h>
#define ll long long
using namespace std;


bool equl(int mat1[],int mat2[]){
    for(int i = 0; i < 26;++i){
        if(mat1[i] != mat2[i]) return 0;
    }
    return 1;
}

int main(){
    int t; scanf(" %d",&t);
    while(t--){
        string re1,re2;
        cin >> re1 >> re2;
        if(re1.size() > re2.size()){
            puts("NO");
            continue;
        }
        int comp[26];
        memset(comp,0,sizeof(comp));
        int temp[26];
        memset(temp,0,sizeof(temp));
        for(auto va:re1)
            ++comp[va-'a'];
        for(int i = 0; i < re1.size();++i)
            ++temp[re2[i]-'a'];
        if(equl(temp,comp)){
            puts("YES");continue;
        }
        bool sti = 0;
        for(int i = re1.size();i < re2.size() && !sti;++i){
            --temp[re2[i-(int)re1.size()]-'a'];
            ++temp[re2[i]-'a'];
            sti = equl(temp,comp);
        }
        if(sti) puts("YES");
        else puts("NO");
    }
    return 0;
}
