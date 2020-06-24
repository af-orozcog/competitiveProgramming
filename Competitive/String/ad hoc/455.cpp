#include<bits/stdc++.h>
using namespace std;

string P;
int b[1000];

void kmpPreprocess(){
    int i = 0, j = -1; b[0] = -1;
    while(i < P.size()){
        while(j >= 0 && P[i] != P[j]) j = b[j];
        ++i,++j;
        b[i] = j;
    }
}

int main(){
    int t;
    cin >> t;
    bool fi = 0;
    while(t--){
        if(fi) cout << "\n";
        cin >> P;
        kmpPreprocess();
        int imp = b[(int)P.size()];
        int yup = (int)P.size()-imp;
        if((int)P.size() % yup == 0)
            cout << yup << "\n";
        else
            cout << P.size() << "\n";
        fi = 1;
    }
    return 0;
}
