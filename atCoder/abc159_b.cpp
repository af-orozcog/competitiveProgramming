#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

bool isPalin(string &re){
    for(int i = 0, j = re.size()-1;i < j;++i,--j){
        if(re[i] != re[j]) return 0;
    }
    return 1;
}

int main(){
    string re;
    cin >> re;
    string fi = re.substr(0,(int)re.size()>>1);
    string se = re.substr(((int)re.size()>>1)+1,re.size());
   // cout << fi << " " << se << "\n";
    if(isPalin(re) && isPalin(fi) && isPalin(se))
        puts("Yes");
    else puts("No");
    return 0;
}
