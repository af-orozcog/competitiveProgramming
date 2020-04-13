#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    for(int i = 0; i < t;++i){
        string re;
        cin >> re;
        int im = 0, iM = 0, ans = 0;
        for(auto va:re){
            if(va == 'I')++iM;
            else if(va == 'i')++im;
            else{
                if(va == 'o' && im)--im;
                else if(va == 'o') --iM;
                else if(va == 'O' && iM) ++ans,--iM;
                else if(va == 'O') --im;
            }
        }
        cout << "Case #" << (i+1)<< ": " << ans << "\n";
    }
    return 0;
}
