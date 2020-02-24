#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int> s;
    int a,b,c;
    scanf(" %d %d %d",&a,&b,&c);
    s.insert(a);s.insert(b);s.insert(c);
    if(s.size() == 2) puts("Yes");
    else puts("No");
    return 0;
}
