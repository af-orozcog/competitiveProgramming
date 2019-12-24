#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> let(26);
string comp;

int main(){
    string re;
    cin >> re >> comp;
    for(int i = 0; i < re.size();++i) let[re[i]-'a'].push_back(i);
    vector<int> be,en;
    if(let[comp[0]-'a'].size())
        be.push_back(let[comp[0]-'a'][0]);
    for(int i = 1; i < comp.size() && be.size();++i){
        int index = lower_bound(let[comp[i]-'a'].begin(),let[comp[i]-'a'].end(),be.back()+1)-let[comp[i]-'a'].begin();
        if(index == let[comp[i]-'a'].size()) break;
        be.push_back(let[comp[i]-'a'][index]);
    }
    if(let[comp[comp.size()-1]-'a'].size())
        en.push_back(let[comp[comp.size()-1]-'a'].back());
    for(int i = comp.size()-2;i > -1 && en.size();--i){
        int index = lower_bound(let[comp[i]-'a'].begin(),let[comp[i]-'a'].end(),en.back())-let[comp[i]-'a'].begin();
        --index;
        if(index < 0) break;
        en.push_back(let[comp[i]-'a'][index]);
    }
    reverse(en.begin(),en.end());
    int ans = en.size();
    int le = -1,ri = (int)comp.size()-(int)en.size();
    for(int i = 0; i < be.size() && ans != comp.size();++i){
        int index = lower_bound(en.begin(),en.end(),be[i]+1)-en.begin();
        int see = ((int)en.size()-index);
        if(see + i+1 > ans){
            ans = see + i + 1;
            le = i; ri = (int)comp.size() - ((int)en.size()-index);
        }
    }
    //cout << be.size() <<" " << en.size() <<endl;
    for(int i = 0; i <= le;++i)
        printf("%c",comp[i]);
    for(int i = ri; i < comp.size();++i)
        printf("%c",comp[i]);
    if(ans == 0) printf("-");
    puts("");
    return 0;
}
