#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

string prune(string &imp){
    string ans = "";
    bool ignore = 0;
    vector<pair<string,int>> op;
    bool ign = 0;
    string temp = "";
    for(int i = 0; i < imp.size();++i){
        ans += imp[i];
        if(ign && imp[i] != ']') continue;
        else if(ign == 1) ign = 0;
        else if(imp[i] == '[') ign = 1;
        else if(imp[i] == '('){
            if(temp == "concat" || !ignore){
                op.push_back({temp,0});
                if(temp != "concat") ignore = 1;
            }
            else{
                for(int j = 0;j <= (int)temp.size();++j)
                    ans.pop_back();
                op.back().second++;
            }
            temp = "";
        }
        else if(imp[i] == ')'){
            if(op.back().second > 0){
                ans.pop_back();
                op.back().second--;
            }
            else{
                if(op.back().first != "concat")
                    ignore = 0;
                op.pop_back();
            }
        }
        else if(imp[i] != ',') temp += imp[i];
    }
    return ans;
}

vector<int> fin;
vector<int> shuf;
int co = 1;
int cop = -1;
void solve(string &imp){
    vector<string> op;
    string wut = imp;
    string last = "";
    bool impp = 0;
    string digi = "";
    string opp = "";
    for(int i = 0; i < imp.size();++i){
        if(imp[i] == '[')
            impp = 1;
        else if(impp){
            if(imp[i] == ',' || imp[i] == ']'){
                fin.push_back(stoi(digi));
                digi = "";
                if((int)last.size() == 0) shuf.push_back(0);
                else if(last == "shuffle")
                    shuf.push_back(co);
                else
                    shuf.push_back(cop);
                if(imp[i] == ']') impp = 0;
            }
            else digi += imp[i];
        }
        else if(imp[i] == '('){
            op.push_back(opp);
            if(op.back() != "concat") last = op.back();
            opp = "";
        }
        else if(imp[i] == ')'){
            if(op.back() != "concat"){last = "";++co,--cop;}
            op.pop_back();
        }
        else if(imp[i] != ',')
            opp += imp[i];
    }
}

void sor(vector<int> &vals,vector<int> &imp){
    int first = -1,last = -1;
    for(int i = 0; i < vals.size();++i){
        if(imp[i] < 0){
            if(first == -1) first = i,last = i;
            else{
                if(imp[i-1] != imp[i]){
                    sort(vals.begin()+first,vals.begin()+last+1);
                    first = i,last = i;
                }
                else last = i;
            }
        }
        else if(last != -1){
            sort(vals.begin()+first,vals.begin()+last+1);
            first = last = -1;
        }
    }
    if(first != -1)
        sort(vals.begin()+first,vals.begin()+last+1);
}

void clean(vector<int> &ar,vector<int> &imp){
    int last = -1;
    int dif = 0;
    if(imp.size() == 1){
        imp[0] = 0; return;
    }
    for(int i = 0; i < (int)imp.size()-1;++i){
        if(imp[i] == last){
            if(ar[i] != ar[i-1]) dif = 1;
            if(imp[i+1] != imp[i] && !dif){
                int j = i;
                while(j > -1 && imp[j] == last){
                    imp[j] = 0;
                    --j;
                }
            }
            continue;
        }
        if(imp[i] != imp[i+1]) imp[i] = 0,dif = 0;
        else if(imp[i] == imp[i+1] && imp[i] != 0) last = imp[i],dif = 0;
        else last = -1,dif = 0;
    }
    if(imp.back() != last)
        imp[(int)imp.size()-1] = 0;
    else if(ar[(int)ar.size()-1] == ar[(int)ar.size()-2] && !dif){
        int j = (int)ar.size()-1;
        while(j > -1 && imp[j] == last){
            imp[j] = 0;
            --j;
        }
    }
}

int main(){
    string lin1,lin2;
    cin >> lin1 >> lin2;
    lin1 = prune(lin1);
    lin2 = prune(lin2);
    solve(lin1);
    vector<int> obta1 = fin;
    vector<int> shuff1 = shuf;
    fin.clear();
    shuf.clear();
    solve(lin2);
    vector<int> obta2 = fin;
    vector<int> shuff2 = shuf;
    fin.clear();
    shuf.clear();
    sor(obta1,shuff1);
    sor(obta2,shuff2);
    for(int i = 0; i < shuff1.size();++i) if(shuff1[i] < 0) shuff1[i] = 0;
    for(int i = 0; i < shuff2.size();++i) if(shuff2[i] < 0) shuff2[i] = 0;
    clean(obta1,shuff1);
    clean(obta2,shuff2);
    if(obta1.size() != obta2.size()){
        puts("not equal"); return 0;
    }
    else{
        bool posi = 1;
        vector<int> aux1,aux2;
        for(int i = 0; i < shuff1.size() && posi;++i){
            if(shuff1[i] != shuff2[i]){
                if(shuff1[i] == 0 || shuff2[i] == 0)
                    posi = 0;
                else if(i > 0 && shuff1[i] == shuff1[i-1]){
                    if(shuff2[i] != shuff2[i-1]) posi = 0;
                    aux1.push_back(obta1[i]);
                    aux2.push_back(obta2[i]);
                }
                else if(shuff1[i] != shuff1[i-1]){
                    if(shuff2[i] == shuff2[i-1]) posi = 0;
                    if(aux1.size()){
                        sort(aux1.begin(),aux1.end());
                        sort(aux2.begin(),aux2.end());
                        if(aux1 != aux2) posi = 0;
                    }
                    aux1.push_back(obta1[i]);
                    aux2.push_back(obta2[i]);
                }
                else{
                    aux1.push_back(obta1[i]);
                    aux2.push_back(obta2[i]);
                }
            }
            else{
                if(obta1[i] != obta2[i])
                    posi = 0;
            }
        }
        if(aux1.size()){
            sort(aux1.begin(),aux1.end());
            sort(aux2.begin(),aux2.end());
            if(aux1 != aux2) posi = 0;
        }
        if(posi) cout << "equal\n";
        else cout << "not equal\n";
    }
    return 0;
}
