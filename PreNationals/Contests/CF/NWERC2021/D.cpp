#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> pi;

ll dist(ll a, ll b){
    return a*a + b*b;
}

int n;

void getAns(int x1,int x2, int y1, int y2){
    if(x1 > x2 || y1 > y2) return;
    bool keep = 0;
    ll imp = dist((y2-y1)/2-1,(y2-y1)/2-1);
    if((y2-y1+1)%2 == 0){
        ll query1,query2,query3,query4;
        cout << (x1+x2)/2 << " " << (y1+y2)/2 << endl;
        cin >> query1;
        if(query1 == 0) --n;
        if(n == 0) return;
        cout << (x1+x2)/2+1 << " " << (y1+y2)/2 << endl;
        cin >> query2;
        if(query2 == 0) --n;
        if(n == 0) return;
        cout << (x1+x2)/2 << " " << (y1+y2)/2+1 << endl;
        cin >> query3;
        if(query3 == 0) --n;
        if(n == 0) return;
        cout << (x1+x2)/2+1 << " " << (y1+y2)/2+1 << endl;
        cin >> query4;
        if(query4 == 0) --n;
        if(n == 0) return;
        if(query1 <= imp) keep = 1;
        if(query2 <= imp) keep = 1;
        if(query3 <= imp) keep = 1;
        if(query4 <= imp) keep = 1;
    }
    else{
        cout << (x1+x2)/2 << " " << (y1+y2)/2 << endl;
        ll query1; cin >> query1;
        if(query1 == 0) --n;
        if(query1 <= imp) keep = 1;
    }
    if(keep && x1 != x2 && n != 0){
        getAns(x1,(x1+x2)/2,y1,(y1+y2)/2);
        getAns(x1,(x1+x2)/2,(y1+y2)/2+1,y2);
        getAns((x1+x2)/2+1,x2,y1,(y1+y2)/2);
        getAns((x1+x2)/2+1,x2,(y1+y2)/2+1,y2);
    }
}

int main(){
    cin >> n;
    getAns(0,1000000,0,1000000);
    return 0;
}
