#include <bits/stdc++.h>
using namespace std;
typedef double T;

struct pt {
    T x,y;
    int group;
    pt operator+(pt p) {return {x+p.x, y+p.y};}
    pt operator-(pt p) {return {x-p.x, y-p.y};}
    pt operator*(T d) {return {x*d, y*d};}
    pt operator/(T d) {return {x/d, y/d};} // only for floatingpoint
};
ostream& operator<<(ostream& os, pt p) {
    return os << "("<< p.x << "," << p.y << ")";
}
bool operator==(pt a, pt b) {return a.x == b.x && a.y == b.y;}
bool operator!=(pt a, pt b) {return !(a == b);}

T sq(pt p) {return p.x*p.x + p.y*p.y;}
double abs(pt p) {return sqrt(sq(p));}
T cross(pt v, pt w) {return v.x*w.y - v.y*w.x;}
T dot(pt v, pt w) {return v.x*w.x + v.y*w.y;}

bool intersection_segment_ray(pt p, pt r, pt a, pt b){
    pt s = b-a;
    T tn = cross((a-p), s);
    T un =cross((a-p), r);
    T den = cross(r,s);
    if(den==0){
        if(un == 0){
            T t0 = dot((a-p), r)/dot(r,r);
            T t1 = dot((b-p), r)/dot(r,r);
            return t1>=0 || t0>=0;
        }
        return false;
    }
    T t =tn/den, u = un/den;
    if(t>= 0 && u>= 0 && u<= 1) return true;
    return false;
}

bool half(pt p) {
    assert(p.x != 0 || p.y != 0);
    return p.y > 0 || (p.y == 0 && p.x < 0);
}

void polarSort(vector<pt> &v) {
    sort(v.begin(), v.end(), [](pt v, pt w) {
        return make_tuple(half(v), 0) < make_tuple(half(w), cross(v,w));
    });}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        vector<pt> send;
        int type1 = 0;
        for(int i = 0; i < n;++i){
            T x,y;
            int type;
            scanf(" %lf %lf %d",&x,&y,&type);
            pt add;
            if(type == -1)type = 0;
            else ++type1;
            add.x = x, add.y = y,add.group = type;
            send.push_back(add);
        }
        polarSort(send);
        int dif = 0;
        double pi = 2*acos(0.0);
        for(int i = 0; i < n;++i)
            send.push_back(send[i]);
        int posi = 0;
        for(int i = 0,j = 0; j < n*2 && !posi;){
            if(!send[j].group){
                ++j;
                i = j;
                continue;
            }
            else{
                double va1,va2;
                if(j >= n) va2 = atan2(send[j].y,send[j].x)+2*pi;
                else va2 = atan2(send[j].y,send[j].x);
                if(i >= n) va1 = atan2(send[i].y,send[i].x)+2*pi;
                else va1 = atan2(send[i].y,send[i].x);
                if(va2-va1 < pi){
                    if(j-i+1 == type1) posi = 1;
                    ++j;
                }
                else
                    ++i;
            }
        }
        if(!posi) puts("NO");
        else puts("YES");
    }
    return 0;
}
