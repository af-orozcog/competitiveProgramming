#include<bits/stdc++.h>
using namespace std;

int main(){
    string n;
    cin >> n;
    int i = 1;
    int ans = 0;
    while(1){
        string check = "";
        int temp = i;
        while(temp){
            if(temp&1)check += '1';
            else check += '0';
            temp >>=1;
        }
        reverse(check.begin(),check.end());
        if(check.size() > n.size() || (check.size() == n.size() && check > n)) break;
        ++i;
        ++ans;
    }
    printf("%d\n",ans);
    return 0;
}
