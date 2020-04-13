#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string re;
        cin >> re;
        int mi = 1;
        int last = re.size();
        for(int i = re.size()-1; i > -1;--i){
            mi = max(mi,last-i);
            if(re[i] == 'R') last = i;
        }
        mi = max(mi,last+1);
        printf("%d\n",mi);
    }
    return 0;
}
