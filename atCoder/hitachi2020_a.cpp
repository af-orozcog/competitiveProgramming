#include<bits/stdc++.h>
using namespace std;

int main(){
    string re;
    cin >> re;
    if(re.size()&1){puts("No");return 0;}
    char comp[] = {'h','i'};
    for(int i = 0, j = 0; i < re.size();++i){
        if(re[i] != comp[j]){puts("No");return 0;}
        j += 1;
        j = j % 2;
    }
    puts("Yes");
    return 0;
}
