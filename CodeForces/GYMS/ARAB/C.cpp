#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("coffee.in","r",stdin);
    int t;
    cin >> t;
    while(t--){
        int c,p;
        cin >> c >> p;
        unordered_map<string,int> smal,medi,larg;
        for(int i = 0; i < c;++i){
            string na;int a,b,d;
            cin >> na >> a >> b >> d;
            smal[na] = a,medi[na] = b, larg[na] = d;
        }
        int add = 100/p;
        for(int i = 0; i < p;++i){
            string na,siz,nam;
            cin >> na >> siz >> nam;
            int sum;
            if(siz[0] == 's'){
                sum = smal[nam];
                sum += add;
                if((sum + 1)%5 == 0)++sum;
                else if((sum-1)%5 == 0)--sum;
            }
            else if(siz[0] == 'm'){
                sum = medi[nam];
                sum += add;
                if((sum + 1)%5 == 0)++sum;
                else if((sum-1)%5 == 0)--sum;
            }
            else{
                sum = larg[nam];
                sum += add;
                if((sum+ 1)%5 == 0)++sum;
                else if((sum-1)%5 == 0)--sum;
            }
            cout << na << " " << sum << "\n";
        }
    }
    return 0;
}
