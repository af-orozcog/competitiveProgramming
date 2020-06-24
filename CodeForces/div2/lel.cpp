#include<bits/stdc++.h>
using namespace std;

int main(){
    for(int i = 0; i < 30;++i){
        cout << "i is: " << i << " ";
        cout << (i%2)%7 << " " << (i%7)%2 << "\n";
    }
    return 0;
}
