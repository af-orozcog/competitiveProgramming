#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
const int MAXN = 1e5+5;
int a[26][MAXN],t[26][4*MAXN],lazy[26][4*MAXN];
//funcion para construir el segtree
void build(int who,int v,int tl,int tr){
    if(tl==tr)
        t[who][v]=a[who][tl];
    else{
        int tm = (tl+tr)/2;
        build(who,v*2,tl,tm);
        build(who,v*2+1,tm+1,tr);
        t[who][v]= t[who][v*2]+t[who][v*2+1];

    }

}
//funcion para propagar el valor a los hijos del nodo.
void push(int who,int v, int tl, int tr){
    int tm = (tl+tr)/2;
    t[who][v*2]=lazy[who][v]*(tm-tl+1);
    lazy[who][v*2]=lazy[who][v];
    t[who][v*2+1]=lazy[who][v]*(tr-tm);
    lazy[who][v*2+1]=lazy[who][v];
    lazy[who][v]=-1;
}
//funcion para hacer update de un rango con un valor dado.
void update(int who,int v,int tl, int tr, int l, int r,int val){
    if(l>r)
        return;
    if(l==tl&&tr==r){
        t[who][v]=val*(tr-tl+1);
        lazy[who][v]=val;
    }
    else{
        //solo es necesario propagar el valor si existe un valor lazy guardado.
        if(lazy[who][v]!=-1)
            push(who,v,tl,tr);
        int tm=(tl+tr)/2;
        update(who,v*2,tl,tm,l,min(tm,r),val);
        update(who,v*2+1,tm+1,tr,max(l,tm+1),r,val);
        t[who][v]= t[who][v*2]+t[who][v*2+1];
    }
}
//funcion para realizar range query.
int query(int who,int v, int tl, int tr, int l, int r){
    if(l>r)
        return 0;
    if(tl==l&&tr==r){
        return t[who][v];

    }
    if(lazy[who][v]!=-1)
        push(who,v,tl,tr);
    int tm = (tl+tr)/2;
    return query(who,v*2,tl,tm,l,min(r,tm))+query(who,v*2+1,tm+1,tr,max(tm+1,l),r);
}
int n,m,i,j;
int main(){
    memset(lazy,-1,sizeof(lazy));
    scanf(" %d %d",&n,&m);
    for(int i = 0; i < 26;++i)
        build(i,1,0,n-1);
    for(int i = 0; i < n;++i){
        char temp; scanf(" %c",&temp);
        update(temp-'a',1,0,n-1,i,i,1);
    }
    for(int i = 0; i < m;++i){
        int from,to,sense;
        scanf(" %d %d %d",&from,&to,&sense);
        --from,--to;
        int seen = 0;
        for(int i = 0;i < 26 && sense;++i){
            int how = query(i,1,0,n-1,from,to);
            update(i,1,0,n-1,from,to,0);
            update(i,1,0,n-1,from+seen,from+seen+how-1,1);
            seen += how;
            how = query(i,1,0,n-1,from,to);
        }
        for(int i = 25; i > -1 && !sense;--i){
            int how = query(i,1,0,n-1,from,to);
            update(i,1,0,n-1,from,to,0);
            update(i,1,0,n-1,from+seen,from+seen+how-1,1);
            seen += how;
        }
    }
    for(int i = 0; i < n;++i){
        for(int j = 0; j < 26;++j){
            if(query(j,1,0,n-1,i,i)){printf("%c",j+'a');break;}
        }
    }
    return 0;
}
