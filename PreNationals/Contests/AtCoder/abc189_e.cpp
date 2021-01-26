#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;
typedef vector<vector<ll>> matrix;

matrix multiply(matrix a, matrix b){
     matrix mult(2,vector<ll>(2));
     for(int i = 0; i < a.size(); ++i)
        for(int j = 0; j < a.size(); ++j)
            for(int  k = 0; k < a.size(); ++k)
            {
                mult[i][j] += a[i][k] * b[k][j];
            }
    return mult;
}

matrix xLine(int x){
    matrix part1 = {{-1,0},{0,1}};
    matrix part2 = {{1,1},{2,0}};
    return ;
}

matrix yLine(int y){
    matrix ans = {{1,0},{1,0}};
    return ans;
}

matrix left(){
    matrix ans = {{0,-1},{1,0}};
    return ans;
}

matrix right(){
    matrix ans = {{0,1},{-1,0}};
    return ans;
}

vector<matrix> operations;


pi where(pi point, matrix &mul){
    pi ans = {point.first*mul[0][0] + point.second*mul[0][1],point.first*mul[1][0] + point.second*mul[1][1]};
    return ans;
}

int main(){
    matrix identity = {{1,0},{0,1}};
    operations.push_back(identity);
    int n;
    scanf(" %d",&n);
    vector<pi> points(n);
    for(int i = 0; i < n;++i) scanf(" %lld %lld",&points[i].first,&points[i].second);
    int m;
    scanf(" %d",&m);
    while(m--){
        int t,p;
        scanf(" %d",&t);
        if(t == 1)
            operations.push_back(multiply(right(),operations.back()));
        else if(t == 2)
            operations.push_back(multiply(left(),operations.back()));
        else if(t == 3){
            scanf(" %d",&p);
            operations.push_back(multiply(xLine(p),operations.back()));
        }
        else{
            scanf(" %d",&p);
            operations.push_back(multiply(yLine(p),operations.back()));
        }
    }
    int q;
    scanf(" %d",&q);
    while(q--){
        int a,b;
        scanf(" %d %d",&a,&b);
        --b;
        pi ans = where(points[b],operations[a]);
        printf("%lld %lld\n",ans.first,ans.second);
    }
    return 0;
}
