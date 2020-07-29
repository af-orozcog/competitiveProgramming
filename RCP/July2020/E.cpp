#include<bits/stdc++.h>
using namespace std;

int main(){
    string line;
    int words = 0;
    getline(cin,line);
    stringstream ss(line);
    string lel;
    while(ss >> lel)
        ++words;
    int n;
    cin >> n;
    string names[n];
    for(int i = 0; i < n;++i)
        cin >> names[i];
    vector<string> team[2];
    int start = 0;
    for(int i = 0,j = 0; i < n;++i){
        int who = start;
        int temp = 1;
        while(temp < words || names[who] == "@"){
            if(names[who] != "@")
                ++temp;
            ++who;
            if(who >= n) who -= n;
        }
        team[j].push_back(names[who]);
        names[who] = "@";
        start = who + 1;
        if(start >= n) start -= n;
        ++j;
        j = j&1;
    }
    for(int i = 0; i < 2;++i){
        cout << team[i].size() << "\n";
        for(auto va:team[i])
            cout << va << "\n";
    }
    return 0;
}
