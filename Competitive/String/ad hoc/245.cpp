#include<bits/stdc++.h>
using namespace std;

int main(){
    string re;
    bool fi = 0;
    int val = -1;
    unordered_map<string,int> tr;
    set<pair<int,string>> coolSet;
    while(getline(cin,re)){
        if(re[0] == '0') break;
        fi = 1;
        for(int i = 0; i < re.size();++i){
            if(!isalpha(re[i])){
                if(isdigit(re[i])){
                    string temp = "";
                    while(isdigit(re[i])){
                        temp += re[i];
                        ++i;
                    }
                    --i;
                    int see = stoi(temp);
                    auto it = coolSet.begin();
                    for(int j = 0; j < see-1;++j)
                        ++it;
                    cout << it->second;
                    string bef = it->second;
                    coolSet.erase(it);
                    tr[bef] = val--;
                    coolSet.insert({tr[bef],bef});
                }
                else
                    cout << re[i];
            }
            else{
                string temp = "";
                while(isalpha(re[i])){
                    temp += re[i];
                    ++i;
                }
                --i;
                cout << temp;
                tr[temp] = val--;
                coolSet.insert({tr[temp],temp});
            }
        }
        cout << "\n";
    }
    return 0;
}
