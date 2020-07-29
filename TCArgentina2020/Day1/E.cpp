#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    int n;
    cin >> n;
    int left[n];
    left[0] = 0;
    int nums[n];
    for(int i = 0; i < n;++i){
        cin >> nums[i];
        if(i)
            left[i] = left[i-1] + nums[i-1];
    }
    int time = 0, where = n - 1;
    while(time < left[where]){
        time += nums[where];
        --where;
    }
    ++where;
    int ans = n - where;
    cout << n-ans << " " << ans << "\n";
}
