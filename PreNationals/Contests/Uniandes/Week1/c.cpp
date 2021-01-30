#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int n;
    cin >> n;
    string rep = "";
    unordered_set<string> neg,pos;
    while(n--){
        string re;
        cin >> re;
        if(re[0] == '!'){
            re = re.substr(1,re.size());
            if(pos.count(re)) rep = re;
            neg.insert(re);
        }
        else{
            if(neg.count(re)) rep = re;
            pos.insert(re);
        }
    }
    if(rep.size())
        cout << rep << "\n";
    else
        cout << "satisfiable\n";
    return 0;
}
