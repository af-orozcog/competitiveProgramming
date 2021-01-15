#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;


double distance(double x, double y){
    return sqrt(x*x + y*y);
}

vector<double> limits(int zones){
    vector<double> ans;
    int parts = zones/2;
    double imp = (acos(-1)*2.0)/((double)zones);
    double ini = imp;
    for(int i = 0;i < zones;++i){
        ans.push_back(ini);
        ini += imp;
    }
    return ans;
}


int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int w;
        double b,d,s;
        scanf(" %d %lf %lf %lf",&w,&b,&d,&s);
        int ans = 0;
        int n;
        vector<double> zones = limits(w);
        scanf(" %d",&n);
        while(n--){
            double x,y;
            scanf(" %lf %lf",&x,&y);
            double r = distance(x,y);
            if(r > s) continue;
            if(r <= b){
                ans += 50;
                continue;
            }
            double slope = atan(y/x);
            if(x < 0.0 && y > 0.0)
                slope += acos(-1);
            if(x > 0.0 && y < 0.0)
                slope += acos(-1)*2.0;
            if(x < 0.0 && y < 0.0)
                slope += acos(-1);
            int add = lower_bound(zones.begin(),zones.end(),slope)-zones.begin() + 1;
            if(r < d)
                add <<=1;
            ans += add;
        }
        printf("%d\n",ans);
    }
    return 0;
}
