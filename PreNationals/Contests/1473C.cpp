#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,k;
        scanf(" %d %d",&n,&k);
        vector<int> answer;
        for(int i = k; i >= (k-(n-k));--i){
            answer.push_back(i);
        }
        vector<int> temp;
        for(int i = 1; i < (k-(n-k)) && answer.size() < n;++i){
            temp.push_back(i);
        }
        for(auto va: temp)
            cout << va << " ";
        for(auto va:answer)
            cout << va << " ";
        cout << "\n";
    }
    return 0;
}
