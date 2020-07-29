#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    vector<char> a,b;
    for(int i = 0; i < n;++i){
        char temp;
        scanf(" %c",&temp);
        if(a.size() && a.back() == temp)continue;
        a.push_back(temp);
    }
    if((int)a.size() > 1 && a.back() == a[0]) a.pop_back();
    for(int i = 0; i < n;++i){
        char temp;
        scanf(" %c",&temp);
        if(b.size() && b.back() == temp)continue;
        b.push_back(temp);
    }
    if((int)b.size() > 1 && b.back() == b[0]) b.pop_back();
    if((int)b.size() == n){
        if(a.size() != b.size()){puts("no");return 0;}
        bool posi = 1;
        for(int i = 0; i < a.size() && posi;++i)
            if(a[i] != b[i]) posi = 0;
        if(posi) puts("yes");
        else puts("no");
        return 0;
    }
    if(a.size() > b.size() || (a.size()== b.size() && (int)a.size()!= 1))
        puts("yes");
    else if(a.size()== b.size() && (int)a.size() == 1 && a[0] == b[0])
        puts("yes");
    else puts("no");
    return 0;
}
