#include<bits/stdc++.h>
using namespace std;

unordered_set<string> swapped(string &see){
    int n = see.size();
    unordered_set<string> seen;
    for(int i = 0; i < n-1;++i){
        string temp = see;
        swap(temp[i],temp[i+1]);
        seen.insert(temp);
    }
    return seen;
}

unordered_set<string> missing(string &see){
    unordered_set<string> seen;
    int n = see.size();
    for(int i = 0; i < n;++i){
        string temp = see;
        temp.erase(temp.begin()+i);
        seen.insert(temp);
    }
    return seen;
}

unordered_set<string> added(string &see){
    unordered_set<string> seen;
    int n = see.size();
    for(int i = 0; i <= n;++i){
        for(int j = 'a'; j <= 'z';++j){
            string temp = see;
            temp.insert(temp.begin()+i,j);
            seen.insert(temp);
        }
    }
    return seen;
}

unordered_set<string> misstyping(string &see){
    unordered_set<string> seen;
    for(auto &va:see){
        char original = va;
        for(int i = 'a'; i <= 'z';++i){
            va = i;
            seen.insert(see);
        }
        va = original;
    }
    return seen;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int d;
    cin >> d;
    vector<string> words(d);
    unordered_set<string> complete;
    for(int i = 0; i < d;++i){
        cin >> words[i];
        complete.insert(words[i]);
    }
    vector<vector<unordered_set<string>>> reF(d,vector<unordered_set<string>>(5));
    for(int i = 0; i < d;++i){
        reF[i][0].insert(words[i]);
        reF[i][1] = swapped(words[i]);
        reF[i][2] = missing(words[i]);
        reF[i][3] = added(words[i]);
        reF[i][4] = misstyping(words[i]);
        /*cout <<"important: " <<words[i] << "\n";
        for(auto va:reF[i][3])
            cout << "needed "<<va << "\n";*/
    }
    int n;
    cin >> n;
    int fi = 0;
    while(n--){
        if(fi) cout << "\n";
        fi = 1;
        string wut;
        cin >> wut;
        cout << wut << "\n";
        int atleast = 0;
        for(int i = 0; i < d;++i){
            if(reF[i][0].count(wut)){
                cout << "CORRECT\n";
                atleast = 1;
            }
            else if(reF[i][1].count(wut)){
                atleast = 1;
                cout << "TWO LETTERS TRANSPOSED IN " << words[i] << "\n";
            }else if(reF[i][2].count(wut)){
                atleast = 1;
                cout << "ONE LETTER OMITTED FROM " << words[i] << "\n";
            }else if(reF[i][3].count(wut)){
                atleast = 1;
                cout <<  "ONE LETTER ADDED TO "<< words[i] << "\n";
            }else if(reF[i][4].count(wut)){
                atleast = 1;
                cout << "ONE LETTER DIFFERENT " << words[i] << "\n";
            }
        }
        if(!atleast)
            cout << "UNKNOWN\n";
    }
    return 0;
}
