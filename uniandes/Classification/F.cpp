#include<bits/stdc++.h>
using namespace std;

int main(){
    map<char,string> tr;
    tr['a'] = "@";
    tr['b'] = "8";
    tr['c'] = "(";
    tr['d'] = "|)";
    tr['e'] = "3";
    tr['f'] = "#";
    tr['g'] = "6";
    tr['h'] = "[-]";
    tr['i'] = "|";
    tr['j'] = "_|";
    tr['k'] = "|<";
    tr['l'] = "1";
    tr['m'] = "[]\\/[]";
    tr['n'] = "[]\\[]";
    tr['o'] = "0";
    tr['p'] = "|D";
    tr['q'] = "(,)";
    tr['r'] = "|Z";
    tr['s'] = "$";
    tr['t'] = "']['";
    tr['u'] = "|_|";
    tr['v'] = "\\/";
    tr['w'] = "\\/\\/";
    tr['x'] = "}{";
    tr['y'] = "`/";
    tr['z'] = "2";
    string line;
    string ans = "";
    getline(cin,line);
    for(auto va:line){
        if(tr.count(tolower(va)))
            ans += tr[tolower(va)];
        else
            ans += va;
    }
    cout << ans << "\n";
    return 0;
}
