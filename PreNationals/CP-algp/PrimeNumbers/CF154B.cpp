#include<bits/stdc++.h>
#define ll long long
using namespace std;

bitset<1000000> posi;
vector<int> divi(1000000,-1);

void init(){
    posi.set();
    posi[0] = posi[1] = 0;
    for(ll i = 2; i < 1000000;++i){
        if(posi[i]){
            divi[i] = (int)i;
            for(ll j = i*i; j < 1000000;j+=i) posi[j] = 0, divi[j] = (int)i;
        }
    }
}

unordered_set<int> divisors(int val){
    unordered_set<int> answer;
    while(val != 1){
        answer.insert(divi[val]);
        val /= divi[val];
    }
    return answer;
}


int main(){
    init();
    int n,m;
    scanf(" %d %d",&n,&m);
    unordered_map<int,int> used;
    unordered_set<int> on;
    for(int i = 0; i < m;++i){
        char op; int num;
        scanf(" %c %d",&op,&num);
        if(op == '-'){
            if(on.count(num)){
                unordered_set<int> check = divisors(num);
                for(auto va:check)
                    used.erase(va);
                puts("Success");
                on.erase(num);
            }
            else puts("Already off");
        }
        else{
            if(on.count(num)) puts("Already on");
            else{
                int conf = -1;
                unordered_set<int> check = divisors(num);
                for(auto va:check)
                    if(used.count(va))
                        conf = used[va];
                if(conf == -1){
                    for(auto va:check)
                        used[va] = num;
                    puts("Success");
                    on.insert(num);
                }
                else
                    printf("Conflict with %d\n",conf);
            }
        }
    }
    return 0;
}
