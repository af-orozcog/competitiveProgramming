#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

int let[26];

int main(){
    string re;
    cin >> re;
    for(auto va:re)
        ++let[va-'a'];
    pi ord[26];
    for(int i = 0; i < 26;++i)
        ord[i] = {-let[i],i};
    sort(ord,ord+26);
    for(int i = 0; i < 26;++i){
        for(int j = 0; j < -ord[i].first;++j)
            printf("%c",ord[i].second+'a');
    }
    puts("");
    return 0;
}
