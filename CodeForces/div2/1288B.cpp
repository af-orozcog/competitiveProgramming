#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll a,b;
        cin >> a >> b;
        ll sum = 0;
        ll temp = 9;
        while(temp <= b){
            ++sum;
            temp*= 10;
            temp += 9;
        }
        cout << a*sum << endl;
    }
    return 0;
}
