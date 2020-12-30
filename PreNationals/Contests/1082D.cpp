#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

int main(){
    int n;
    scanf(" %d",&n);
    vector<pi> number(n);
    vector<vector<int>> g(n);
    for(int i = 0; i < n;++i){
        number[i].second = i;
        scanf(" %d",&number[i].first);
    }
    sort(number.begin(),number.end());

}
