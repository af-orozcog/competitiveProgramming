#include<bits/stdc++.h>
#define ll long long
using namespace std;

int fiX, fiY;

void getAns(int x, int y, int moves, int orientation, int multy, int tama){
    if(tama == 1){
        fiX = x;
        fiY = y;
        return;
    }
    if(((tama*tama)>>2) >= moves)
        getAns(x,y,moves,(orientation+1)&1,multy,tama>>1);
    else if(((tama*tama)>>1) >= moves){
        if(orientation)
            getAns(x+(tama/2)*multy,y,moves-((tama*tama)>>2),orientation,multy,tama>>1);
        else
            getAns(x,y+(tama/2)*multy,moves-((tama*tama)>>2),orientation,multy,tama>>1);
    }
    else if(((tama*tama)>>2)*3 >= moves)
        getAns(x+(tama/2)*multy,y+(tama/2)*multy,moves-((tama*tama)>>1),orientation,multy,tama>>1);
    else{
        if(orientation)
            getAns(x+((tama/2)-1)*multy,y+(tama-1)*multy,moves-(((tama*tama)>>2)*3),(orientation+1)&1,multy*-1,tama>>1);
        else
            getAns(x+(tama-1)*multy,y+((tama/2)-1)*multy,moves-(((tama*tama)>>2)*3),(orientation+1)&1,multy*-1,tama>>1);
    }
}

int main(){
    int n,m;
    while(scanf(" %d %d",&n,&m) == 2){
        int x = 1,y = 1;
        getAns(x,y,m,0,1,n);
        printf("%d %d\n",fiX,fiY);
    }
    return 0;
}
