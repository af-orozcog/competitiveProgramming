#include<bits/stdc++.h>
#define ll long long

using namespace std;

int ent[26];
bool marked[26];

int main(){
    int n,k;
    scanf(" %d %d",&n,&k);
    char check[n];
    for(int i = 0; i < n;++i){
        scanf(" %c",&check[i]);
        ++ent[check[i]-'A'];
    }
    for(int i = 0; i < n;++i){
        if(!marked[check[i]-'A'] && k)
            marked[check[i]-'A'] = 1,--k;
        else if(!marked[check[i]-'A']){puts("YES");return 0;}
        --ent[check[i]-'A'];
        if(!ent[check[i]-'A']) ++k;
    }
    puts("NO");
    return 0;
}
