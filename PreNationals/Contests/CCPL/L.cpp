#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> fraction;


void reduce(fraction &frac){
    int g = __gcd(abs(frac.first),abs(frac.second));
    frac.first /= g;
    frac.second /= g;
}

fraction multiply(fraction frac1, fraction frac2){
    fraction answer = {frac1.first*frac2.first,frac1.second*frac2.second};
    reduce(answer);
    return answer;
}

int lcm(int a, int b){
    int g = __gcd(a,b);
    return (a/g)*b;
}

fraction add(fraction frac1,fraction frac2){
    int lc = lcm(frac1.second,frac2.second);
    fraction answer = {(frac1.first*(lc/frac1.second))+(frac2.first*(lc/frac2.second)),lc};
    if(answer.first == 0)
        answer.second = 1;
    reduce(answer);
    return answer;
}

pair<fraction,fraction> lineDef(fraction frac1, fraction frac2){
    fraction slo = {frac1.second-frac2.second,frac1.first-frac2.first};
    if(slo.first == 0 || slo.second == 0)
        return {{0,0},{0,0}};
    if(slo.second < 0)
        slo.first *= -1,slo.second *= -1;
    reduce(slo);
    fraction x = {-frac1.first,1};
    fraction y = {frac1.second,1};
    fraction temp = multiply(slo,x);
    fraction point = add(temp,y);
    return {slo,point};
}

int lessEqual(fraction a, fraction b){
    if(a.first < b.first) return -1;
    if(a.first == b.first){
        if(a.second < b.second)
            return -1;
        if(a.second == b.second)
            return 0;
        if(a.second > b.second) return 1;
    }
    return 1;
}

bool comp(const vector<fraction> a, const vector<fraction> b){
    int upTo = min(a.size(),b.size());
    for(int i = 0; i < upTo;++i){
        int val = lessEqual(a[i],b[i]);
        if(val < 0) return 1;
        if(val > 0) return 0;
    }
    return a.size() < b.size();
}

int main(){
    string line;
    while(1){
        vector<fraction> fractions;
        int x,y;
        unordered_map<int,vector<fraction>> vertical,horizontal;
        int keep = 1;
        while(keep){
            getline(cin,line);
            stringstream ss(line);
            while(ss >> x >> y){
                if(x == 0 && y == 0){
                    keep = 0;
                    continue;
                }
                fractions.push_back({x,y});
                vector<fraction> add1,add2;
                vertical[x] = add1;
                horizontal[y] = add2;
            }
        }
        if(fractions.size() == 0) break;
        sort(fractions.begin(),fractions.end());
        map<pair<fraction,fraction>,vector<fraction>> lines;
        for(int i = 0; i < fractions.size();++i){
            for(int j = i+1; j < fractions.size();++j){
                pair<fraction,fraction> check = lineDef(fractions[i],fractions[j]);
                if(check.first.first == check.first.second && check.first.first == 0)
                    continue;
                vector<fraction> add;
                lines[check] = add;
            }
        }
        for(int i = 0; i < fractions.size();++i){
            vertical[fractions[i].first].push_back(fractions[i]);
            horizontal[fractions[i].second].push_back(fractions[i]);
            for(auto &check:lines){
                pair<fraction,fraction> see = check.first;
                fraction x = {fractions[i].first,1};
                fraction fi = multiply(see.first,x);
                fraction se = add(fi,see.second);
                if(se.second == 1 && se.first == fractions[i].second)
                    check.second.push_back(fractions[i]);
            }
        }
        vector<vector<fraction>> answers;
        for(auto &check:vertical)
            if(check.second.size() > 2)
                answers.push_back(check.second);
        for(auto &check:horizontal)
            if(check.second.size() > 2)
                answers.push_back(check.second);
        for(auto &check:lines)
            if(check.second.size() > 2)
                answers.push_back(check.second);
        sort(answers.begin(),answers.end(),comp);
        if(answers.size())
            puts("The following lines were found:");
        else
            puts("No lines were found");
        for(auto &arr:answers){
            for(auto point:arr){
                printf("(%4d,%4d)", point.first, point.second);
            }
            puts("");
        }
    }
    return 0;
}
