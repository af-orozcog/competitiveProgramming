#include<bits/stdc++.h>
using namespace std;

#define MAX 1005

typedef pair<int, int> pii;

vector<pii> pos;
char mat [MAX][MAX];
int n;
bool valido(int x){
    return x>=0 && x<n;
}
bool check_king(int f, int c){
    int ops[] = {-1,0,1};
    for(int i = 0; i<3; ++i){
        for(int j = 0; j<3; ++j){
            int nf = f+ops[i], nc = c+ops[j];
            if(valido(nf) && valido(nc)){
//                cout<<"valido "<<nf<<" "<<nc<<" "<<mat[nf][nc]<<endl;
                if(mat[nf][nc]=='K'){
                    return true;
                }
            }
        }
    }
    return false;
}

bool check_peon(int f, int c){
    int nf = f+1, nc = c-1;
//    cout<<nf<<" "<<nc<<" "<<mat[nf][nc]<<"\n";
    if(valido(nf) && valido(nc) && mat[nf][nc]=='P') return true;
    nc = c+1;
    if(valido(nf) && valido(nc) && mat[nf][nc]=='P') return true;
    return false;
}

int main(){
    //freopen("1.in", "r", stdin);
    cin>>n;
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<n; ++j){
             cin>>mat[i][j];
             if(mat[i][j]=='*'){
                pos.push_back({i,j});
             }
        }
    }
    int rta = 0;
    for(auto x: pos){
        int f = x.first, c = x.second;
//        cout<<f<<" "<<c<<"\n";
        if(check_king(f, c)) continue;
        if(check_peon(f, c)) continue;
        int of = f+1, oc = c+1;
//        cout<<of<<" "<<oc<<"  \n";
        if(valido(of) && valido(oc)){

            if(mat[of][oc]=='-') {
                rta++;
                mat[of][oc]='P';
                continue;
//                cout<<"holi\n";
            }
        }
        oc = c-1;
        if(valido(of) && valido(oc)){
            if(mat[of][oc]=='-') {
                rta++;
                mat[of][oc]='P';
                continue;
            }
        }
        cout<<-1<<"\n";
        return 0;

    }
    cout<<rta<<"\n";
}
