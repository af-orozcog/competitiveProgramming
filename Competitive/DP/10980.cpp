#include<bits/stdc++.h>
using namespace std;

int main(){
    int i = 1;
    string line;
    while(getline(cin,line)){
        stringstream ss(line);
        string va;
        ss >> va;
        int m; ss>>m;
        int nums[m+1];
        int of[m+1];
        nums[m] = stoi(va.substr(0,(int)va.size()-3));
        of[m] = 1;
        for(int i = 0; i < m;++i){
            getline(cin,line);
            stringstream ss(line);
            int m;
            ss>>m; ss >> va;
            of[i] = m;
            nums[i] = stoi(va.substr(0,(int)va.size()-3));
        }
        getline(cin,line);
        stringstream ss1(line);
        vector<int> queries;
        int temp, ma = 0;
        while(ss1 >> temp){
            queries.push_back(temp);
            if(temp > ma) ma = temp;
        }
        int dp[ma+1];
        dp[0] = 0;
        for(int i = 1; i <= ma;++i){
            dp[i] = 1000000000;
            for(int j = 0; j < m+1;++j){
                if(i - of[j] > -1)
                    dp[i] = min(dp[i],dp[i-of[j]] + nums[j]);
            }
        }
        for(auto va:queries){

        }
    }
}
