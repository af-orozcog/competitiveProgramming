#include<bits/stdc++.h>
using namespace std;


string ans = "";
int found = 0;

void check(vector<vector<char>> &ma,string &pos){
    if(found) return;
    if(ma.size() == 0){
        found = 1;
        ans = pos;
        return;
    }
    vector<vector<char>> co = ma;
    for(int i = 0; i < ma.size() && !found;++i){
        char del = ma[i][0];
        pos += del;
        bool send = 1;
        for(int i = 0; i < ma.size() && send;++i){
            for(int j = 0; j < ma[i].size() && send;++j){
                if(ma[i][j] == del && j != 0) send = 0;
                else if(ma[i][j] == del){
                    ma[i].erase(ma[i].begin()+j);
                    --j;
                }
            }
            if((int)ma[i].size() == 0){
                ma.erase(ma.begin()+i);
                --i;
            }
        }
        if(send){
            check(ma,pos);
            break;
        }
        pos.pop_back();
        ma = co;
    }
}

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        int n,m;
        scanf(" %d %d",&n,&m);
        found = 0;
        vector<vector<char>> matrix(m);
        for(int i = 0; i < n;++i){
            for(int j = 0; j < m;++j){
                char va; scanf(" %c",&va);
                matrix[j].push_back(va);
            }
        }
        for(int i = 0; i < m;++i)
            reverse(matrix[i].begin(),matrix[i].end());
        string pos = "";
        check(matrix,pos);
        cout << "Case #" << cas++ << ": ";
        if(found) cout << ans << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}
