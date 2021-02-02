#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    string re;
    getline(cin,re);
    stringstream ss(re);
    string temp;
    vector<string> words;
    char punc[] = {',','.','?','!'};
    while(ss>>temp){
        for(auto see:punc){
            size_t where = 0;
            while((where = temp.find(see,where)) != string::npos){
                temp.insert(temp.begin()+where+1,' ');
                ++where;
            }
        }
        words.push_back(temp);
    }
    for(int i = 0; i < words.size();++i){
        if(i){
            bool one = 0;
            for(auto see:punc)
                one = one | (words[i-1].back() == see || words[i][0] == see);
            if(!one) cout << " ";
        }
        cout << words[i];
    }
    return 0;
}
