#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool checkSum(vector<vector<ll>> &matrix, int left, int right){

}

ll binary(vector<vector<ll>> &matrix){
    ll ans = -1;
    int lo1 = 1, hi1 = (int)matrix.size()-1;
    while(lo1 <= hi1){
        int mid1 = (lo1+hi1)>>1;
        int lo2 = 1,hi2 = (int)matrix[0].size()-1,ans2 = -1;
        while(lo2 <= hi2){
            int mid2 = (lo2+hi2)>>1;
            if()
        }
        if(ans2 == 1)
    }
    return ans;
}

int main(){
    ll r,c,s;
    scanf(" %lld %lld %lld",&r,&c,&s);
    vector<vector<ll>> matrix(r,vector<ll>(c));
    for(int i = 0; i < r;++i){
        for(int j = 0;j < c;++j)
            scanf(" %lld",&matrix[i][j]);
    }

}
