#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        vector<char> word(n);
        for(int i = 0; i < n;++i) scanf(" %c",&word[i]);
        while(word.size() && word.back()-'0' % 2 == 0){
            word.pop_back();
        }
        int imp = 0;
        for(int i = 0; i < word.size();++i){
            if(word[i]-'0' % 2 == 1) ++imp;
        }
        if(imp&1){
            for(int i = 0; i < word.size();++i){
                if(word[i]-'0' % 2 == 1){
                    word.erase(word.begin()+i);
                    break;
                }
            }
        }
        reverse(word.begin(),word.end());
        while(word.size() && word.back()-'0' == 0) word.pop_back();
        reverse(word.begin(),word.end());
        if(word.size() == 0) word = {'-','1'};
        for(int i = 0; i < word.size();++i) printf("%c",word[i]);
        puts("");
    }
    return 0;
}
