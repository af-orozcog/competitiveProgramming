/**
* here comes machete :v
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int nums[100005];

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,m;
        scanf(" %d %d",&n,&m);
        vector<vector<int>> graph(n);
        vector<bool> marked(n,false);
        while(m--){
            int a,b;
            scanf(" %d %d",&a,&b);
            --a,--b;
            connect(a,b);
        }
    }
    return 0;
}
