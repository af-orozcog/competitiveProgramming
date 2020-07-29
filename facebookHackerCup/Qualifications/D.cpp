#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1e6+5;
ll a[MAXN],t[4*MAXN];

ll check = 100000000000000000LL;

void build(int v, int tl, int tr){
    if(tl==tr)
        t[v]=a[tl];
    else{
        int tm = (tl+tr)/2;
        build(v*2,tl,tm);
        build(v*2+1,tm+1,tr);
        //depende la operación a realizar.
        t[v] = min(t[v*2],t[v*2+1]);
    }
}
ll get(int v, int tl, int tr, int l, int r){
    if(l>r)
        //retornar valor neutro de la opéración.
        return check;
    if(tl==l&&tr==r)
        return t[v];
    int tm = (tl+tr)/2;
    return min(get(v*2,tl,tm,l,min(r,tm)),get(v*2+1,tm+1,tr,max(tm+1,l),r));

}
void update(int v,int tl, int tr, int pos, ll new_val){
    if(tl==tr)
        t[v]=new_val;
    else{
        int tm  = (tl+tr)/2;
        if(pos<=tm)
            update(v*2,tl,tm,pos,new_val);
        else
            update(v*2+1,tm+1,tr,pos,new_val);
        t[v]=min(t[v*2],t[v*2+1]);
    }
}
ll nums[1000002];
int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        int n,m;
        scanf(" %d %d",&n,&m);
        for(int i = 0; i < n;++i){
            scanf(" %lld",&a[i]);
            //ll wut = a[i];
            if(a[i] == 0ll)
                a[i] = check;
        }
        a[n-1] = 0ll;
        build(1,0,n-1);
        ll ans;
        for(int i = n-2; i > -1;--i){
            if(i){
                ll see = get(1,0,n-1,i+1,min(n-1,i+m));
                see += a[i];
                if(see >= check)
                    update(1,0,n-1,i,check);
                else
                    update(1,0,n-1,i,see);
            }
            else
                ans = get(1,0,n-1,i+1,min(n-1,i+m));
        }
        printf("Case #%d: ",cas++);
        if(ans == check)
            printf("%lld\n",-1LL);
        else
            printf("%lld\n",ans);
    }
    return 0;
}
