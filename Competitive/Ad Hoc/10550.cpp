#include<bits/stdc++.h>
using namespace std;

int main(){
    int s,f1,f2,f3;
    while(scanf(" %d %d %d %d",&s,&f1,&f2,&f3) && (s || f1 || f2 || f3)){
        //cout << "lil " << s <<endl;
        int ans = (360<<1);
        int mov = 9;
        while(s != f1){
            --s;
            ans += mov;
            if(s == -1) s = 39;
            //cout << s << endl;
        }
        ans += 360;
        while(f1 != f2){
            ++f1;
            ans += mov;
            if(f1 == 40) f1 = 0;
        }
        while(f2 != f3){
            --f2;
            ans += mov;
            if(f2 == -1) f2 = 39;
        }
        printf("%d\n",ans);
    }
    return 0;
}
