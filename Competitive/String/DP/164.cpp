#include<bits/stdc++.h>
using namespace std;

string changeFormat(int i){
    string ans = "";
    if(i < 10)
        ans += '0';
    ans += to_string(i);
    return ans;
}

int main(){
    string a,b;
    while(1){
        cin >> a;
        if(a[0] == '#')break;
        cin >> b;
        int dp[21][21];
        for(int i = 0; i < (int)a.size()+1; ++i) dp[0][i] = i;
        for(int i = 0; i< (int)b.size()+1;++i) dp[i][0] = i;
        for(int i = 1; i <= b.size();++i){
            for(int j = 1; j <= a.size();++j){
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + 1;
                if(a[j-1] == b[i-1])
                    dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
                else
                    dp[i][j] = min(dp[i][j],dp[i-1][j-1]+1);
              //  cout << dp[i][j] << " ";
            }
            //cout << "\n";
        }
        int i = b.size();
        int j = a.size();
        vector<string> ans;
        while(i != 0 || j != 0) {
            string let1 = "", let2 = "";
            if (j)
                let1 += a[j - 1];
            if (i)
                let2 += b[i - 1];
            string change1 = changeFormat(max(i+1,1));
            string change2 = changeFormat(max(i,1));
            int next = 1000000000;
            int neI = i, neJ = j;
            bool changed = 0;
            if (i && j && dp[i - 1][j - 1] < next) {
                if (a[j - 1] != b[i - 1]) {
                    changed = 1;
                    ans.push_back("C" + let2 + change2);
                }
                next = dp[i - 1][j - 1];
                neI = i - 1;
                neJ = j - 1;
            }
            if (j && dp[i][j - 1] < next) {
                if (changed) ans.pop_back();
                ans.push_back("D" + let1 + change1);
                next = dp[i][j - 1];
                neI = i;
                neJ = j - 1;
                changed = 1;
            }
            if (i && dp[i - 1][j] < next) {
                if (changed) ans.pop_back();
                //cout << 3 << "\n";
                ans.push_back("I" + let2 + change2);
                next = dp[i - 1][j];
                neI = i - 1;
                neJ = j;
                changed = 1;
            }
            i = neI;
            j = neJ;
            //cout << next << " " << neI << " " << neJ << "\n";
        }
        reverse(ans.begin(),ans.end());
        ans.push_back("E");
        for(auto va:ans)
            cout << va;
        cout <<"\n";
    }
    return 0;
}
