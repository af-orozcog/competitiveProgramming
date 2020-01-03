#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    return __gcd(a,b);
}

pair<int,int> simp(pair<int,int> a){
    int div = gcd(abs(a.first),abs(a.second));
    pair<int,int > ans;
    ans.first = a.first/div;
    ans.second = a.second/div;
    return ans;
}

int main(){
    int n;
    int ex,ey,ez;
    scanf(" %d %d %d %d",&n,&ex,&ey,&ez);
    //cout << ex << " " << ey << " " << ez << endl;
    set<pair<pair<int,int>,pair<pair<int,int>,pair<int,int>>>> dif;
    for(int i = 0; i < n-1;++i){
        int x,y,z;
        scanf(" %d %d %d",&x,&y,&z);
        int neX = ex-x,neY = ey-y,neZ = ez-z;
        pair<int,int> val1 = {neY,neX};
        pair<int,int> val2 = {neZ,neX};
        pair<int,int> val3 = {neY,neZ};
       // cout << val1.first << "/" << val1.second << " "<< val2.first << "/" << val2.second << " " << val3.first << "/" << val3.second << endl;
        if(val1.first < 0 && val1.second < 0){ val1.first = abs(val1.first),val1.second = abs(val1.second);}
        else if(val1.second < 0){ val1.first = -val1.first,val2.second = abs(val1.second);}
        if(val2.first < 0 && val2.second < 0){ val2.first = abs(val2.first),val2.second = abs(val2.second);}
        else if(val2.second < 0){val2.first = -val2.first; val2.second = abs(val2.second);}
        if(val3.first < 0 && val3.second < 0){ val3.first = abs(val3.first),val3.second = abs(val3.second);}
        else if(val3.second < 0){ val3.first = -val3.first,val3.second = abs(val3.second);}
        if(val1.first == 0) val1.second = 1;
        else if(val1.second == 0) val1.first = 1;
        else
            val1 = simp(val1);
        if(val2.first == 0) val2.second = 1;
        else if(val2.second == 0) val2.first = 1;
        else
            val2 = simp(val2);
        if(val3.first == 0) val3.second = 1;
        else if(val3.second == 0) val3.first = 1;
        else
            val3 = simp(val3);
        //cout << val1.first << "/" << val1.second << " "<< val2.first << "/" << val2.second << " " << val3.first << "/" << val3.second << endl;
        dif.insert({val1,{val2,val3}});
    }
    printf("%d\n",(int)dif.size());
    return 0;
}
