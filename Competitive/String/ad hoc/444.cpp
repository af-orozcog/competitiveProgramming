#include<bits/stdc++.h>
using namespace std;

bool inverse(string &re,string &ans, int i){
    if(i == (int)re.size())return true;
    string posi1 = re.substr(i,2);
    if(posi1.size() == 1)return false;
    reverse(posi1.begin(),posi1.end());
    int va1 = stoi(posi1);
    if(va1 < 123 && va1 > 31){
        char add = va1;
        ans += add;
        if(inverse(re,ans,i+2)) return true;
        ans.pop_back();
    }
    string posi2 = re.substr(i,3);
    if(posi2.size() == 2) return false;
    reverse(posi2.begin(),posi2.end());
    int va2 = stoi(posi2);
    if(va2 < 123 && va2 > 31){
        char add = va2;
        ans += add;
        if(inverse(re,ans,i+3)) return true;
        ans.pop_back();
    }
    return false;
}

int main(){
    string line;
    while(getline(cin,line)){
        if(line.size() == 0)cout << "\n";
        else if(!isdigit(line[0])){
            string ans = "";
            for(int i = line.size()-1; i > -1;--i){
                int wut = line[i];
                string to_add = to_string(wut);
                reverse(to_add.begin(),to_add.end());
                ans += to_add;
            }
            //reverse(ans.begin(),ans.end());
            cout << ans << "\n";
        }
        else{
            string ans = "";
            inverse(line,ans,0);
            reverse(ans.begin(),ans.end());
            cout << ans << "\n";
        }
    }
    return 0;
}
