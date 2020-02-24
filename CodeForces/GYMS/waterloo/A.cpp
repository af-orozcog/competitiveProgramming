#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    return b == 0? a: gcd(b,a%b);
}
int lcm(int a, int b){
    return (a/gcd(a,b))*b;
}

int main(){
    int a,b,c;
    scanf(" %d %d %d",&a,&b,&c);
    int up = lcm(a,b);
    up = lcm(up,c);
    priority_queue<pair<int,int>> q;
    q.push({-(up/a),a}); q.push({-(up/c),b}); q.push({-(up/b),c});
    int wa,wb,wc;
    wa = wb = wc = 1;
    int where = 0;
    vector<int> ans1,ans2,ans3,ans4;
    while(q.top().first != -up){
        int f1 = -q.top().first, f2 = q.top().second;
        q.pop();
        q.push({-(f1+up/f2),f2});
        if(f1 >= where){
            if(f2 == a) ++wa;
            if(f2 == b) ++wb;
            if(f2 == c) ++wc;
            continue;
        }
        ans1.push_back(f1-where);ans2.push_back(wa);ans3.push_back(wb);ans4.push_back(wc);
        if(f2 == a) ++wa;
        if(f2 == b) ++wb;
        if(f2 == c) ++wc;
    }
    printf("%d\n",(int)ans1.size());
    for(int i = 0; i < ans1.size();++i)
        printf("%d %d %d %d",ans1[i],ans2[i],ans3[i],ans4[i]);
    return 0;
}
