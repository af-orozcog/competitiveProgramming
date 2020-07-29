#include<stdio.h>
#define ll long long
#define max(x,y)(x > y? x:y)

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        ll a[n],b[n];
        for(int i = 0;i < n;++i)
            scanf(" %lld",&a[i]);
        for(int i = 0;i < n;++i)
            scanf(" %lld",&b[i]);
        ll acum = b[0];
        int posi = 1;
        for(int i = 1; i < n && posi;++i){
            ll see = max(0ll,a[i]-acum);
            if(see > b[i]) posi = 0;
            acum = b[i]-see;
            //	printf("%d ",see);
        }
        ll needed = max(0,a[0]-acum);
        if(!posi || needed > b[0]){puts("NO");continue;}
        //printf("%d\n",needed);
        acum = b[0]-needed;
        for(int i = 1; i < n && posi;++i){
            ll see = max(0,a[i]-acum);
            if(see > b[i]) posi = 0;
            acum = b[i]-see;
        }
        if(!posi || a[0] > needed+acum){puts("NO");continue;}
        puts("YES");
    }
    return 0;
}
