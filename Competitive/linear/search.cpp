#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
using namespace std;

bool inside(vector<string> data, string word){
    //cout << "la palabra que llega es: " << word << endl;
    if(word.compare("") == 0){
        return true;
    }
    for(int i = 0; i < data.size();i++){
        if(data[i].compare(word) == 0)
            return true;
    }
    return false;
}
bool mySort(pair<int,pair<string,string>> a, pair<int,pair<string,string>> b){
    if(a.second.second.compare(b.second.second) > 0)
        return false;
    if(a.second.second.compare(b.second.second) < 0)
        return true;
    else
        return a.first < b.first;
}
int main(){
    vector<string> toIgnore;
    string val;
    cin >> val;
    while(val.compare("::") != 0){
        for_each(val.begin(), val.end(), [](char & c){
    c = ::tolower(c);});
        toIgnore.push_back(val);
        cin >> val;
    }
    vector<string> titles;
    while(getline(cin,val)){
        for_each(val.begin(), val.end(), [](char & c){
    c = ::tolower(c);});
        titles.push_back(val);
    }
    vector<pair<int,pair<string,string>>> diff;
    int number = 0;
    for(int i = 0; i < titles.size(); i++){
        int j = 0;
        while(j < titles[i].size()){
            string word = "";
            while(j < titles[i].size()){
                if(titles[i][j] == ' '){
                    j++;
                    break;
                }
                word+=titles[i][j++];
            }
            if(!inside(toIgnore,word)){
                string lel = "b";
                lel = titles[i];
                for_each(word.begin(), word.end(), [](char & c){
    c = ::toupper(c);});
                if(j == titles[i].size())
                    lel.replace(j-(word.size()),word.size(),word);
                else{
                    lel.replace(j-(word.size()+1),word.size(),word);
        //            cout << lel << endl;
                }
                diff.push_back(make_pair(number++,make_pair(lel,word)));     
            }
        }
    }
    sort(diff.begin(),diff.end(),mySort);
    for(int i = 0; i < diff.size(); i++){
        cout << diff[i].second.first << endl;
    }
    return 0;
}