#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    char vals[] = {'v','<','^','>'};
    char start,fin;
    int mov;
    scanf(" %c %c",&start,&fin);
    scanf(" %d",&mov);
    int po1,po2;
    for(int i = 0; i < 4;++i){
        if(vals[i] == start) po1 = i;
        if(vals[i] == fin) po2 = i;
    }
    int ri = (po1 + mov)%4;
   // cout << ri << endl;
    int le = (((po1 -mov)%4)+4)%4;
    if(le == ri && ri == po2) puts("undefined");
    else if(ri == po2) puts("cw");
    else puts("ccw");
    return 0;
}
