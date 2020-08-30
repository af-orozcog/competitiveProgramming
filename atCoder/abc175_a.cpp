#include<bits/stdc++.h>
using namespace std;

int main(){
    string days;
    cin >> days;
    int start = days[0] == 'R';
    int ans = start;
    for(int i = 1; i < days.size();++i){
        if(days[i] != 'R')
            start = 0;
        else
            ++start;
        ans = max(ans,start);
    }
    cout << ans << "\n";
    return 0;
}
