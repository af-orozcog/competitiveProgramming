#include<bits/stdc++.h>
using namespace std;

int n,k;

bool dfs(vector<set<int>> &rowU,vector<set<int>> &colU, vector<vector<int>> &matrix, int row, int col){
    if(row == n)
        return 1;
    if(matrix[row][col] != 0){
         int neR = (col == n-1?row+1:row),neC = (col == n-1?0:col+1);
        if(dfs(rowU,colU,matrix,neR,neC)) return 1;
    }
    for(int i = 1; i <= n;++i){
        if(rowU[row].count(i) || colU[col].count(i))continue;
        rowU[row].insert(i);colU[col].insert(i);
        matrix[row][col] = i;
        int neR = (col == n-1?row+1:row),neC = (col == n-1?0:col+1);
        if(dfs(rowU,colU,matrix,neR,neC)) return 1;
        matrix[row][col] = 0;
        rowU[row].erase(i);colU[col].erase(i);
    }
    return 0;
}

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        scanf(" %d %d",&n,&k);
        printf("Case #%d: ",cas++);
        if(k%n == 0){
            puts("POSSIBLE");
            vector<int> show(n);
            show[0] = k/n;
            for(int i = 1,j = 1; i < n;++i){
                if(j == show[0])++j;
                show[i] = j++;
            }
            for(int i = 0; i < n;++i){
                for(auto va:show) printf("%d ",va);
                puts("");
                show.insert(show.begin(),show.back());
                show.pop_back();
            }
            continue;
        }
        vector<vector<int>> matrix(n,vector<int> (n));
        int sum = n;
        if(sum > k) {puts("IMPOSSIBLE");continue;}
        vector<int> dia(n,1);
        for(int i = 0; i < dia.size() && sum < k;++i){
            while(dia[i] < n && sum < k)
                ++dia[i],++sum;
        }
        vector<set<int>> rowU(n),colU(n);
        if(sum  < k){
            puts("IMPOSSIBLE"); continue;
        }
        for(int i = 0; i < n;++i){
            matrix[i][i] = dia[i];
            rowU[i].insert(dia[i]);
            colU[i].insert(dia[i]);
        }
        if(k < n || !dfs(rowU,colU,matrix,0,0)){puts("IMPOSSIBLE");continue;}
        puts("POSSIBLE");
        for(int i = 0; i < n;++i){
            for(int j = 0; j < n;++j)printf("%d ",matrix[i][j]);
            puts("");
        }
    }
    return 0;
}
