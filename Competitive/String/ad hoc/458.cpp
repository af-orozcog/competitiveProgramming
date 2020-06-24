#include<bits/stdc++.h>
using namespace std;

int main(){
    string line;
    while(getline(cin,line)){
        for(auto va:line){
            char show = va-7;
            cout << show;
        }
        cout << "\n";
    }
    return 0;
}
