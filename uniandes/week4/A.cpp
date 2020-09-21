#include<bits/stdc++.h>
using namespace std;

int main(){
    string re;
    cin >> re;
    int seen[26] = {0};
    int dif = 0;
    for(auto va:re){
        if(!seen[va-'a'])
            ++dif,seen[va-'a'] = 1;
    }
    if(dif&1) puts("IGNORE HIM!");
    else puts("CHAT WITH HER!");
    return 0;
}
