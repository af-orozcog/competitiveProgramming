#include<bits/stdc++.h>
using namespace std;

struct pt{
    double x,y;
    int group;
};


double ConvertR(double degree){
    double pi = 2*acos(0.0);
    return (degree* (pi / 180));
}

double ConvertD(double radian){
    double pi = 2*acos(0,0);
    return (radian * (180/pi));
}

bool pointsAreOnSameSideOfLine(double a, double b, double c,
                        double x1,    double y1, double x2, double y2)
{
    double fx1; // Variable to store a * x1 + b * y1 - c
    double fx2; // Variable to store a * x2 + b * y2 - c

    fx1 = a * x1 + b * y1 - c;
    fx2 = a * x2 + b * y2 - c;

    // If fx1 and fx2 have same sign
    if ((fx1 * fx2) > 0.0)
        return true;

    return false;
}

bool onLine(double a, double b, double x, double y){
    return a/b*x == y;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        vector<pt> points(20);
        for(int i = 0; i < n;++i){
            double x,y;
            int g;
            scanf(" %lf %lf %d",&x,&y,&g);
            points[i].x = x,points.y = y, points.group = g;
        }
        int posi = 0;
        for(int i = 0; i < 360 && !posi;++i){
            double rad = ConvertR(i);
            double a = sin(rad), b = cos(rad);
            int seen = -1;
            for(int i = 0; i < n && seen == -1;++i){
                if(!onLine(a,b,points[i].x,points[i].y))
                    seen = i;
            }
            if(seen == -1){
                posi = 1;
                continue;
            }
            for(int i = 0; i < n;++i){
                if(onLine(a,b,points[i].x,points[i].y)) continue;

            }
        }
        if(posi) puts("YES");
        else puts("NO");
    }
}
