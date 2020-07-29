#include<bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    int first = 1;
    while(getline(cin,a)){
        getline(cin,b);
        if(!first) cout << "\n";
        first = 0;
        int dp[(int)a.size()+1][(int)b.size()+1];
        for(int i = 0; i <= (int)a.size();++i) dp[i][0] = i;
        for(int i = 0; i <= (int)b.size();++i) dp[0][i] = i;
        for(int i = 1; i <= (int)a.size();++i){
            for(int j = 1; j <= (int)b.size();++j){
                dp[i][j] = dp[i-1][j-1] + (a[i-1] != b[j-1]);
                dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
                dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
            }
        }
        vector<int> position;
        vector<string> action;
        vector<char> letter;
        int i = a.size(), j = b.size();
        while(i != 0 || j != 0){
            int next = 100000000;
            int neI = i, neJ = j;
            int seen = 0;
            if(i && j && dp[i-1][j-1] < next){
                if(a[i-1] != b[j-1]){
                    position.push_back(j);
                    action.push_back("Replace");
                    letter.push_back(b[j-1]);
                    seen = 1;
                }
                next = dp[i-1][j-1];
                neI = i-1;
                neJ = j-1;
            }
            if(j && dp[i][j-1] < next){
                if(seen){position.pop_back();action.pop_back();letter.pop_back();}
                position.push_back(j);
                action.push_back("Insert");
                letter.push_back(b[j-1]);
                next = dp[i][j-1];
                neI = i;
                neJ = j-1;
                seen = 1;
            }
            if(i && dp[i-1][j] < next){
                if(seen){position.pop_back();action.pop_back();letter.pop_back();}
                position.push_back(j+1);
                action.push_back("Delete");
                letter.push_back('l');
                neI = i-1;
                neJ = j;
            }
            i = neI;
            j = neJ;
        }
        reverse(position.begin(),position.end());
        reverse(action.begin(),action.end());
        reverse(letter.begin(),letter.end());
        cout << position.size() << "\n";
        for(int i = 0; i < position.size();++i){
            cout << i+1 << " ";
            if(action[i] == "Delete")
                cout << action[i] << " " << position[i] << "\n";
            else
                cout << action[i] << " " << position[i] << "," << letter[i] <<"\n";
        }
    }
    return 0;
}
