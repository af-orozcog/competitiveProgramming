/**
* El hombre bocachico nos bendiga
* y la arawana nos de fuerza
*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
typedef pair<ll,ll> pi;

ll dp[1006][1006];

int main(){
    vector<vector<ll>> matrix;
    string re;
    while(getline(cin,re)){
        stringstream ss;
        ss << re;
        ll num;
        vector<ll> nums;
        while(ss >> num){
            nums.pb(num);
           // cout << num << endl;
        }
        matrix.pb(nums);
    }
    for(int i = 0; i < 1000;++i){
        for(int j = 0; j < 1000;++j) dp[i][j] = 100000000000ll;
    }
    dp[999][999] = matrix[999][999];
    for(int i = 999; i > -1;--i){
        for(int j = 999; j > -1;--j){
            if(j != 999)
                dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i][j+1]);
            if(i != 999)
                dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i+1][j]);
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}
