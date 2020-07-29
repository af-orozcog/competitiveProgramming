#include<bits/stdc++.h>
using namespace std;

class BagPacking{
    public:
    int minPay(vector <int> bagsizes){
        map<int,int> tr;
        for(auto va:bagsizes)
            ++tr[va];
        int resp = 0;
        for(auto &va:tr)
            resp = max(resp,va.second);
        return resp;
    }
};

int main(){
    return 0;
}
