#include <iostream>
#include <cstring>
using namespace std;
int main(void){
    int n, m;
    cin >> m >> n;
    int p[n][m]; int f[n][m]; int c[n][m];
    memset(f,0,sizeof(f));
    memset(c,0,sizeof(c));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int r; scanf(" %d",&r);
            p[i][j] = r;
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(j == 0)
                f[i][j] = (p[i][j] == 1);
            else
                f[i][j] = f[i][j-1] + (p[i][j] == 1);  
        }
    }
   for(int j = 0; j<m; ++j){
        for(int i = 0; i<n; ++i){
            if(i == 0)
                c[i][j] = (p[i][j] == 1);
            else
                c[i][j] = c[i-1][j] + (p[i][j] == 1); 
        }
    }
    int cont = 0;
     for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(p[i][j] == 0){
                if(j>= 1 && f[i][j-1] >= 1){
                    cont++;
                }if(f[i][m-1] - f[i][j]){
                    cont++;
                }if(i>= 1 && c[i-1][j] >= 1){
                    cont++;
                }if(c[n-1][j] - c[i][j]){
                    cont++;
                }
            }
        }
     }
    cout << cont << endl;
}