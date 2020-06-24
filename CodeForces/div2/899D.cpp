#include<bits/stdc++.h>
#define ll long long
using namespace std;

int allNine(int check){
    while(check){
        if(check%10 != 9) return 0;
        else check = check/10;
    }
    return 1;
}

int main(){
    int n;
    scanf(" %d",&n);
    int see = n+(n-1);
    if(allNine(see)){
        puts("1");
        return 0;
    }
    string wut = to_string(see);
    string check = "";
    string anns = "";
    for(int i = 0; i < (int)wut.size()-1;++i)
        check += '9',anns += '9';
    int lel = stoi(check);
    anns[0] = '4';
    int ansReal = stoi(anns);
    if(n < lel-1){
        ansReal -= lel-1-n;
    }
    if(n > lel){
        string wuut = to_string(n);
        int mul = 1;
        for(char i = '0'; i < wuut[0]-1;++i)
            mul++;
        wuut[0] = '0';
        int nn = stoi(wuut);
        ansReal = ansReal*mul+ansReal;
        if(nn < lel-1){
            ansReal -= max(lel-1-nn,0);
        }
    }
    printf("%d\n",max(0,ansReal));
    return 0;
}
