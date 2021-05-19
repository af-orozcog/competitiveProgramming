#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<double,pair<double,double>> point;


double biggest(double x, double y, double z, vector<point> &points){
    double ans = 0;
    for(auto &point:points){
        ans = max(ans,sqrt((x-point.f)*(x-point.f) + (y-point.s.f)*(y-point.s.f) + (z-point.s.s)*(z-point.s.s)));
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<point> points(n);
    for(int i = 0; i < n;++i)
        cin >> points[i].first >> points[i].second.first >> points[i].second.second;

    double ans = numeric_limits<double>::max();
    for(int i = 0; i < n;++i){
        for(int j = i+1; j < n;++j){
            ans = min(ans,biggest(ceil((points[i].f+points[j].f)/2.0),ceil((points[i].s.f+points[j].s.f)/2.0),ceil((points[i].s.s+points[j].s.s)/2.0),points));
            ans = min(ans,biggest(floor((points[i].f+points[j].f)/2.0),ceil((points[i].s.f+points[j].s.f)/2.0),ceil((points[i].s.s+points[j].s.s)/2.0),points));
            ans = min(ans,biggest(ceil((points[i].f+points[j].f)/2.0),floor((points[i].s.f+points[j].s.f)/2.0),ceil((points[i].s.s+points[j].s.s)/2.0),points));
            ans = min(ans,biggest(floor((points[i].f+points[j].f)/2.0),floor((points[i].s.f+points[j].s.f)/2.0),ceil((points[i].s.s+points[j].s.s)/2.0),points));
            ans = min(ans,biggest(ceil((points[i].f+points[j].f)/2.0),ceil((points[i].s.f+points[j].s.f)/2.0),floor((points[i].s.s+points[j].s.s)/2.0),points));
            ans = min(ans,biggest(floor((points[i].f+points[j].f)/2.0),ceil((points[i].s.f+points[j].s.f)/2.0),floor((points[i].s.s+points[j].s.s)/2.0),points));
            ans = min(ans,biggest(ceil((points[i].f+points[j].f)/2.0),floor((points[i].s.f+points[j].s.f)/2.0),floor((points[i].s.s+points[j].s.s)/2.0),points));
            ans = min(ans,biggest(floor((points[i].f+points[j].f)/2.0),floor((points[i].s.f+points[j].s.f)/2.0),floor((points[i].s.s+points[j].s.s)/2.0),points));
        }
    }
    cout << ans << "\n";
    return 0;
}
