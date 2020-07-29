#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
const int MAXN = 100000;
int a[MAXN],t[4*MAXN];
int ar1[MAXN],ar2[MAXN];
//funcion para construir el segtree
void build(int v, int tl, int tr){
	if(tl==tr)
		t[v]=a[tl];
	else{
		int tm = (tl+tr)/2;
		build(v*2,tl,tm);
		build(v*2+1,tm+1,tr);
		//depende la operación a realizar.
		t[v]= max(t[v*2],t[v*2+1]);
	}
}
int get(int v, int tl, int tr, int l, int r){
	if(l>r)
		//retornar valor neutro de la opéración.
		return 0;
	if(tl==l&&tr==r)
		return t[v];
	int tm = (tl+tr)/2;
	return max(get(v*2,tl,tm,l,min(r,tm)),get(v*2+1,tm+1,tr,max(tm+1,l),r));

}
void update(int v,int tl, int tr, int pos, int new_val){
	if(tl==tr)
		t[v]=new_val;
	else{
		int tm  = (tl+tr)/2;
		if(pos<=tm)
			update(v*2,tl,tm,pos,new_val);
		else
			update(v*2+1,tm+1,tr,pos,new_val);
		t[v]=max(t[v*2],t[v*2+1]);
	}
}
int n,as,bs;
int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
	while(t--){
	    memset(ar2,-1,sizeof(ar2));
        scanf(" %d %d %d",&n,&as,&bs);
		for(int i = 0; i<bs; i++)
            a[i] = 0;
        build(1,0,bs-1);
        for(int i = 0; i <= as;++i) scanf(" %d",&ar1[i]);
        for(int i = 0; i <= bs;++i) {
            int temp;
            scanf(" %d",&temp);
            ar2[temp] = i;
        }
        ar1[as] = 0;
        for(int i = as-1; i > -1;--i){
            if(ar2[ar1[i]] == -1) {ar1[i] = ar1[i+1];continue;}
            int cop = ar1[i];
            //cout << "before from here on " << ar2[ar1[i]] << " " << get(1,0,bs-1,ar2[ar1[i]],bs-1) << "\n";
            ar1[i] = max(1+get(1,0,bs-1,ar2[ar1[i]],bs-1),ar1[i+1]);
            update(1,0,bs-1,ar2[cop],1+get(1,0,bs-1,ar2[cop],bs-1));
            //cout << "after from here on " << ar2[cop] << " " << get(1,0,bs-1,ar2[cop],bs-1) << "\n";
        }
        printf("Case %d: %d\n",cas++,ar1[0]+1);
	}
    return 0;
}
