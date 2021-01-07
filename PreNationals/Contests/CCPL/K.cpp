#include<bits/stdc++.h>
using namespace std;

bool works(const char a, const char b){
    if(a != b) return 1;
    if(a == '1') return 1;
    return false;
}

bool valid(string &a,string &b, int from1, int from2){
    while(from1 < a.size() && from2 < b.size() && works(a[from1],b[from2]))
        ++from1,++from2;
    return (from1 == a.size() || from2 == b.size());
}

int main(){
    string a,b;
    while(cin >> a >> b){
        int ans = a.size() + b.size();
        for(int i = 0; i < a.size();++i){
            if(valid(a,b,i,0)){
                int sz = max((int)a.size(),i+(int)b.size());
                ans = min(sz,ans);
            }
        }
        for(int i = 0; i < b.size();++i){
            if(valid(b,a,i,0)){
                int sz = max((int)b.size(),i+(int)a.size());
                ans = min(sz,ans);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
