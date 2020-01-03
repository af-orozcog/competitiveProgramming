#include<bits/stdc++.h>
using namespace std;

int matrix[100][100];
int eva[100][100];

int main(){
    int n;
    while(cin >> n && n){
        cin.ignore();
        for(int i = 0; i < 100;++i){
            for(int j = 0; j < 100;++j) matrix[i][j] = eva[i][j] = 10000000;
            matrix[i][i] = eva[i][i] = 0;
        }
        string line;
        for(int i = 0;i < n;++i){
            getline(cin,line);
            stringstream ss(line);
            int from;
            ss >> from;
            --from;
            int to;
            while(ss >> to){
                --to;
                matrix[from][to] = 1;
            }
        }
        for(int i = 0; i < n;++i){
            getline(cin,line);
            stringstream ss(line);
            int from;
            ss >> from; --from;
            int to;
            while(ss >> to){
                --to;
                eva[from][to] = 1;
            }
        }
        for(int k = 0; k < n;++k){
            for(int i = 0; i < n;++i){
                for(int j = 0; j < n;++j)
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]),eva[i][j] = min(eva[i][j],eva[i][k] + eva[k][j]);
            }
        }
        int A,B;scanf(" %d %d",&A,&B);
        //cout << A << " " << B << endl;
        bool posi = 1;
        for(int i = 0; i < n && posi;++i){
            for(int j = 0; j < n && posi;++j){
                //cout <<matrix[i][j] << " " << eva[i][j] << endl;
                if(matrix[i][j]*A + B < eva[i][j]) posi = 0;
            }
        }
        if(posi) puts("Yes");
        else puts("No");
    }
}
