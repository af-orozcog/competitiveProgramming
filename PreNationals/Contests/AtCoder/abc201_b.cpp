#include<bits/stdc++.h>
using namespace std;

int main(){
    string first = "",second = "";
    int f = 0,s = 0;
    int n;
    cin >> n;
    while(n--){
        string name; int he;
        cin >> name >> he;
        if(he > f){
            s = f;
            second = first;
            f = he;
            first = name;
        }
        else if(he > s){
            s = he;
            second = name;
        }
    }

    cout << second << "\n";
    return 0;
}
