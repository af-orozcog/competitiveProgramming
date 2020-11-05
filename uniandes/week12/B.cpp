#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;string re;
        cin >> n >> re;
        int left = 0, right = re.size()-1;
        int turn = 0;
        while(n--){
            int cut = (right-left+1)>>2;
            if(!cut) break;
            if(!turn)
                left += cut;
            else
                right -= cut;
            turn = (turn+1)&1;
        }
        cout << re.substr(left,right-left+1) << "\n";
    }
    return 0;
}
