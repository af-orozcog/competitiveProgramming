#include<bits/stdc++.h>
using namespace std;

int main(){
    string re;
    cin >> re;
    set<int> good;
    good.insert(0);
    for(int i = 1; i < 1000; ++i){
        int see = (i*i)*3 + i;
        if(see%8 == 0){
            good.insert(i);
            //cout << i << "\n";
        }
    }
    string see = re.substr(max(0,(int)re.size()-3),3);
    int nu = stoi(see);
    auto va = good.lower_bound(nu);
    int tar;
    if(va == good.end()) tar = 1000;
    else tar = *va;
    int add = tar - nu;
    string edd = to_string(add);
    int acum = 0;
    for(int i = re.size()-1,j = edd.size()-1; i > -1;--i,--j){
        int dig = re[i]-'0';
        int more = 0;
        if(j > -1) more += edd[j]-'0';
        if(acum) ++more,acum = 0;
        int nedig = dig + more;
        if(nedig > 9) acum = 1;
        re[i] = (nedig%10) + '0';
    }
    if(acum)
        re = "1" + re;
    cout << re << "\n";
}
