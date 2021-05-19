#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string see;
    cin >> see;
    if(n > 26){
        cout << "-1\n";
        return 0;
    }
    int letters[26];
    memset(letters,0,sizeof(letters));
    for(auto &let:see){
        ++letters[let-'a'];
    }
    int ans = 0;
    for(int i = 0; i < 26;++i){
        ans += max(letters[i]-1,0);
    }

    printf("%d\n",ans);
    return 0;
}
