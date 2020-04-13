#include<bits/stdc++.h>
using namespace std;

void cas1(int ar[],int n){
    reverse(ar,ar+n);
}

void cas2(int ar[], int n){
    for(int i = 0; i < n;++i)
        ar[i] = (ar[i]+1)&1;
}

void cas3(int ar[], int n){
    reverse(ar,ar+n);
    for(int i = 0; i < n;++i)
        ar[i] = (ar[i]+1)&1;
}

void cas4(int ar[],int n){
    return;
}

void showAr(int ar[], int n){
    for(int i = 0; i < n;++i)printf("%d ",ar[i]);
    puts("");
}

bool compare(vector<int> &see, int ar[]){
    for(int i = 0; i < see.size();++i)
        if(see[i] != ar[i]) return 0;
    return 1;
}

int main(){
    int n;
    scanf(" %d",&n);
    int ar[n];
    srand ( time(NULL) );
    for(int i = 0; i < n;++i){
        ar[i] = rand()&1;
    }
    showAr(ar,n);
    for(int i = 1,j = 1, k = 100; i <= 100;++i){
        if(i%10 == 1){
            int ask = (rand()%4)+1;
            if(ask == 1) cas1(ar,n);
            else if(ask == 2) cas2(ar,n);
            else if(ask == 3) cas3(ar,n);
            else cas4(ar,n);
        }
        if(i%2 == 0){
            printf("%d\n",ar[j-1]);
            ++j;
        }
        else{
            printf("%d\n",ar[k-1]);
            --k;
        }
    }
    int i = 1;
    while(1){
        if(i%10 == 1){
            int ask = (rand()%4)+1;
            if(ask == 1) cas1(ar,n);
            else if(ask == 2) cas2(ar,n);
            else if(ask == 3) cas3(ar,n);
            else cas4(ar,n);
            showAr(ar,n);
        }
        puts("value you want to know or -1");
        int que;
        scanf(" %d",&que);
        if(que == -1){
            vector<int> comp;
            for(int i = 0; i < n;++i){
                char va;scanf(" %c",&va);
                if(va == '1')comp.push_back(1);
                else comp.push_back(0);
            }
            if(compare(comp,ar)) puts("EQUAL");
            else puts("F");
            break;
        }
        printf("This is the value in that position: %d\n",ar[que-1]);
        ++i;
    }
    int t;
    cin >> t;
    return 0;
}
