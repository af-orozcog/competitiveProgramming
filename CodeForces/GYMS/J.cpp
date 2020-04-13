#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll wut = 1024;

int main(){
    int t;
    cin >> t;
    unordered_map<string,ll> fr;
    fr["bool"] = 1;
    fr["char"] = 1;
    fr["int"] = 4;
    fr["long long"] = 8;
    fr["__int128"] = 16;
    fr["float"] = 4;
    fr["double"] = 8;
    fr["long double"] = 16;
    int cas = 1;
    while(t--){
        int n;
        cin >> n;
        int byte = 0;
        cin.ignore();
        while(n--){
            string line;
            getline(cin,line);
            stringstream ss(line);
            vector<string> lets;
            string temp;
            while(ss >> temp)
                lets.push_back(temp);
            string look = lets[0];
            if(lets.size() > 2){
                look += " ";
                look += lets[1];
            }
            ll va = fr[look];
            string la = lets.back();
            la.pop_back();
            int mul = 1;
            if(la.back() == ']'){
                int found = (int)la.find("[");
                string imp = la.substr(found+1,la.size());
                imp.pop_back();
                //cout << imp << "\n";
                mul = stoi(imp);
            }
            byte += (ll)mul*va;
        }
        ll show = byte/wut;
        if(byte%wut) ++show;
        printf("Case #%d: %lld\n",cas++,show);
    }
    return 0;
}
