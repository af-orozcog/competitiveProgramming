/**
* Lo hago por Valentina, para ser mejor y para llegar a Moscú
*/
#include<iostream>
#include<vector>
#define ll long long
using namespace std;

int main(){
 
  ll n,m;
  while(cin >> n >> m){
    ll matrix[n][m];
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            matrix[i][j] = 0;
        }
    }
    //cout << "que pasa" << endl;
    for(ll i = 0;i < n; i++){
        ll nonZero;
        cin >> nonZero;
        if(nonZero != 0){
            ll indexes[nonZero];
            for(ll w = 0; w < nonZero; w++){
                int vals;
                cin >> vals;
                //cout << "los indexes donde  hay" << vals << endl;
                indexes[w] = vals-1;
            }
            for(ll w = 0; w < nonZero;w++){
                ll vals;
                cin >> vals;
                matrix[i][indexes[w]] = vals;
            }
        }
    }
    cout << m << " " << n << endl;
    for(ll i = 0; i < m; i++){
        vector<ll> indexes;
        ll siz = 0;
        for(int j = 0; j < n; j++){
            if(matrix[j][i] != 0){
                indexes.push_back(j);
                siz++;
            }
    }
    cout << siz;
    for(int w = 0; w < siz; w++){
      cout << " " << indexes[w] +1;
    }
    cout << endl;
    if(siz != 0){
      for(int w = 0; w < siz; w++){
          //cout << "el index es: " << indexes[w] << endl;
        if(w != (siz - 1))
          cout << matrix[indexes[w]][i] << " ";
        else
          cout << matrix[indexes[w]][i];
        }
    }
        cout << endl;
    }
  }
  return 0;
}