#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        string re;
        cin >> re;
        int ones[re.size()];
        int zeros[re.size()];
        if(re[0] == '1'){
            ones[0] = 1;
            zeros[0] = 0;
        }
        else{ones[0] = 0; zeros[0] = 1;}
        for(int i = 1; i < re.size();++i){
            if(re[i] == '1'){ones[i] = 1;zeros[i] = 0;}
            else {zeros[i] = 1; ones[i] = 0;}
            ones[i] += ones[i-1];
            zeros[i] += zeros[i-1];
        }
        int ans = min((int)re.size()-ones[re.size()-1],(int)re.size()-zeros[re.size()-1]);
       // cout << ans << endl;
        //cout << ones[6] << " " << (((int)re.size()-7-1)-(ones[re.size()-1]-ones[7])) << endl;
        for(int i = 0; i < re.size()-1;++i){
            for(int j = i+1; j < re.size();++j){
                int pos1 = ((i+1)-ones[i]) + ((j-i)-(zeros[j]-zeros[i])) + (((int)re.size()-j-1)-(ones[re.size()-1]-ones[j]));
                int pos2 = ((i+1)-zeros[i]) + ((j-i)-(ones[j]-ones[i])) + (((int)re.size()-j-1)-(zeros[re.size()-1]-zeros[j]));
                ans = min(ans,min(pos1,pos2));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
