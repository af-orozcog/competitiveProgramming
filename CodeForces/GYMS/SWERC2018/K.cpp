#include<bits/stdc++.h>
using namespace std;


void lel(string &re, int see){
    string neRe = "";
    string wut = re;
    for(int i = 0;;){
        int j = i + see;
        int eq = 0;
        if(i >= re.size())break;
        while(j < re.size() && re[i] == re[j] && eq!= see){
            ++eq;
            ++j,++i;
        }
        if(eq == see) neRe += re.substr(i,see),i = j;
        else neRe += re[i-eq],i = i - eq+1;
    }
    re = neRe;
}

int main(){
    int n;
    cin >> n;
    string re;
    cin >> re;
    while(1){
        bool keep = 0;
        for(int j = re.size()-1; j > 2;--j){
            int before = re.size();
            lel(re,j);
            if(re.size() != before) keep = 1;
        }
        if(!keep) break;
    }
    printf("%d\n",re.size());
}
