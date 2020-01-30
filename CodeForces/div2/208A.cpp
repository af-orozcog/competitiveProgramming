#include<bits/stdc++.h>
using namespace std;

int main(){
    string re;
    cin >> re;
    char comp[] = {'W','U','B'};
    string con = "";
    int i = 0;
    for(auto va:re){
        con += va;
        if(va == comp[i])
            ++i;
        else
            i = 0;
        if(va == comp[i])
            ++i;
        if(i == 3){
            con.pop_back();con.pop_back();con.pop_back();
            if(con.size() && con.back() != ' ') con += " ";
            i = 0;
        }
    }
    if(con.back() == ' ') con.pop_back();
    cout << con << "\n";
    return 0;
}
