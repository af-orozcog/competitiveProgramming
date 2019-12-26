#include<bits/stdc++.h>
using namespace std;

bool posi(int a,int b,int c,int tar){
    if(tar >= a && tar >= b && tar >= c) return 1;
    else if(a > tar){
        int temp  = a-tar;
        if(b + temp > tar){
            int dif = (b+temp)-tar;
            if(dif <= b) c += dif;
            else return 0;
        }
        if(c <= tar) return 1;
    }
    else if(c> tar){
        int temp = c-tar;
        if(b + temp > tar){
            int dif = (b+temp)-tar;
            if(dif <= b) a += dif;
            else return 0;
        }
        if(a <= tar) return 1;
    }
    else if(b > tar){
        int add = b - tar;
        if(a+add <= tar && c <= tar )return 1;
        else if(c+add <= tar && a <= tar) return 1;
        int left = (min(a,c)+add)-tar;
        if(max(a,c)+left<=tar)return 1;
    }
    return 0;
}

int main(){
   // posi(134,14,798,316);
    int n;
    scanf(" %d",&n);
    while(n--){
        int a,b,c;
        scanf(" %d %d %d",&a,&b,&c);
        int lo = (a+b+c)/3,hi = a+b+c,ans;
        while(lo<=hi){
            int mid = (lo+hi)>>1;
            if(posi(a,b,c,mid)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid +1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
