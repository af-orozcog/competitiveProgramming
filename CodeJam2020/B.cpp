#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        string re;
        cin >> re;
        int co = 0;
        char imp = re[0];
        for(int i = 0; i < imp-'0';++i)
            re.insert(0,"(");
        for(int i = 0; i < re.size()-1;++i){
            if(re[i] == '('){++co;continue;}
            if(re[i] == ')'){--co;continue;}
            char imp = re[i+1];
            if(imp -'0' > co){
                for(int j = co; j < imp-'0';++j)
                    re.insert(i+1,"(");
            }
            else if(imp-'0' < co){
                for(int j = co; j > imp-'0';--j)
                    re.insert(i+1,")");
            }
        }
        while(co) re+=')',--co;
        cout <<"Case #" << cas++ << ": "<< re << "\n";
    }
    return 0;
}
