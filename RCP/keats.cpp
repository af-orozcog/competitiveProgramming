#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string alpha,let;
    cin >> alpha >> let;
    set<string> show;
    for(int i = 0; i < let.size();++i){
        for(auto va:alpha){
            string append = let;
            append[i] = va;
            show.insert(append);
        }
    }
    for(int i = 0;i < let.size();++i){
        for(auto va:alpha){
            string append = let;
            append.insert(append.begin()+i,va);
            show.insert(append);
        }
    }
    for(auto va:alpha){
        string append = let;
        append += va;
        show.insert(append);
    }
    for(int i = 0;i < let.size();++i){
        string append = let;
        append.erase(append.begin()+i);
        show.insert(append);
    }
    show.erase(let);
    for(auto va:show){
        cout << va << "\n";
    }
    return 0;
}
