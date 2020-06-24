#include<bits/stdc++.h>
using namespace std;

string re;
int b[1000005];

void kmpPreprocess(){
    int i = 0, j = -1; b[0] = -1;
    while(i < (int)re.size()){
        while(j >= 0 && re[i] != re[j]) j = b[j];
        ++i,++j;
        b[i] = j;
    }
}


int main(){
    while(1){
        cin >> re;
        if(re[0] == '.' && re.size() == 1)break;
        kmpPreprocess();
        //puts("wtf?");
        int val = b[(int)re.size()];
        //puts("here??");
        //cout << val << "\n";
        int see = (int)re.size()-val;
        if((int)re.size() % see == 0) cout << (int)re.size() / see << "\n";
        else cout << 1 << "\n";
    }
    return 0;
}
