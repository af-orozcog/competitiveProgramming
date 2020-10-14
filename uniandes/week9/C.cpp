#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    cin.ignore();
    string line;
    while(t--){
        getline(cin,line);
        if((int)line.size() <= 4){
            cout << "OMG>.< I don't know!\n";
            continue;
        }
        string first = line.substr(0,5);
        string last = line.substr((int)line.size()-5,5);
        if(first == "miao." && last != "lala.")
            cout << "Rainbow's\n";
        else if(last == "lala." && first != "miao.")
            cout << "Freda's\n";
        else cout << "OMG>.< I don't know!\n";
    }
    return 0;
}
