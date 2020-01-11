#include<bits/stdc++.h>
using namespace std;

int main(){
    string f1 = "0",f2 = "1";
    for(int i = 0; i < 80;++i){
        string temp = f2 + f1;
        f1 = f2;
        f2 = temp;
    }
    cout << f2 << endl;
}
