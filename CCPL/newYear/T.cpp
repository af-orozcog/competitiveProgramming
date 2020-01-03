#include<bits/stdc++.h>
using namespace std;

struct player{
    int number;
    string name;
    char role;
    int time = 0;
};

bool comp(player &a, player &b){
    if(a.number < b.number) return 1;
    else return 0;
}

bool eq(player a,player b){
    if(a.number != b.number) return 0;
    if(a.name.compare(b.name) != 0) return 0;
    if(a.role != b.role) return 0;
    if(a.time != b.time) return 0;
    return 1;
}

int main(){
    string line;
    player jug[22];
    int i = 0;
    while(getline(cin,line)){
        if(line.size() == 1 && line[0] == '0')break;
        if(i != 22){
            stringstream ss(line);
            ss >> jug[i].number;
            ss >> jug[i].name;
            ss >> jug[i].role;
            jug[i].time = 0;
            string temp;
            while(ss>>temp){
                jug[i].time -= stoi(temp.substr(0,4));
                jug[i].time += stoi(temp.substr(5,4));
                ++jug[i].time;
            }
            cout << jug[i].time << endl;
            ++i;
        }
        else{
            i = 0;
            sort(jug,jug+22,comp);
            int D = 0,M = 0,S = 0;
            int j = 0;
            while(line[j] != '-'){
                D *= 10;
                D += line[j]-'0';++j;
            }
            ++j;
            while(line[j] != '-'){
                M *= 10;
                M += line[j]-'0';++j;
            }
            ++j;
            while(line[j] != '-' && j < line.size()){
                S *= 10;
                S += line[j]-'0';++j;
            }
            cout << D << " " << M << " " << S << endl;
            vector<player> def,mid,stri,go;
            for(int i = 0; i < 22;++i){
                if(jug[i].role == 'G') go.push_back(jug[i]);
                else if(jug[i].role == 'D') def.push_back(jug[i]);
                else if(jug[i].role == 'M') mid.push_back(jug[i]);
                else stri.push_back(jug[i]);
            }
           // cout << def.size() << " " << mid.size() << " " << stri.size() << " " << go.size() << " " << endl;
            if(def.size() < D || mid.size() < M || stri.size() < S || go.size() == 0){puts("IMPOSSIBLE TO ARRANGE\n");continue;}
            player cap = go[0];
            vector<player> ans;
            ans.push_back(go[0]);
            for(int i = 0; i < D;++i){
                ans.push_back(def[i]);
                if(cap.time < def[i].time)
                    cap = def[i];
                else if(cap.time == def[i].time && def[i].number > cap.number)
                    cap = def[i];
            }
            for(int i = 0; i < M;++i){
                ans.push_back(mid[i]);
                if(cap.time < mid[i].time)
                    cap = mid[i];
                else if(cap.time == mid[i].time && mid[i].number > cap.number)
                    cap = mid[i];
            }
            for(int i = 0; i < S;++i){
                ans.push_back(stri[i]);
           //     cout << stri[i].time << " " << cap.time << "\n";
                if(cap.time < stri[i].time)
                    cap = stri[i];
                else if(cap.time == stri[i].time && stri[i].number > cap.number)
                    cap = stri[i];
            }
            cout << cap.number << " " << cap.name << " " << cap.role << endl;
            for(int i = 0; i < ans.size(); ++i){
                if(!eq(cap,ans[i]))
                   cout << ans[i].number << " " << ans[i].name << " " << ans[i].role << endl;
            }
            cout << i << endl;
            puts("");
        }
    }
    return 0;
}
