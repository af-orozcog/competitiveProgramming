#include<bits/stdc++.h>
using namespace std;

int main(){
    int p,n;
    cin >> p >> n;
    int day = 1, ans = 0;
    unordered_set<string> st;
    while(n--){
        string see;
        cin >> see;
        if(ans) continue;
        st.insert(see);
        if((int)st.size() == p) ans = day;
        ++day;
    }
    if(!ans) puts("paradox avoided");
    else cout << ans << "\n";
    return 0;
}
