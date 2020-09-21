#include<bits/stdc++.h>
using namespace std;

vector<int> look(string &a, int tama){
    vector<int> kmp(a.size(),0);
    vector<int> answer;
    int border = 0;
    for(int i = 1; i < a.size();++i){
        while(border > 0 && a[i] != a[border])
            border = kmp[border-1];
        if(a[i] == a[border])
            ++border;
        if(border == tama)
            answer.push_back(i-tama+1);
        kmp[i] = border;
    }
    return answer;
}


int main(){
    int t;
    cin >> t;
    int fi = 0;
    while(t--){
        if(fi)puts("");
        fi = 1;
        string a,b;
        cin >> a >> b;
        string send = b+"$"+a;
        vector<int> toShow = look(send,b.size());
        if(!toShow.size())
            puts("Not Found");
        else{
            printf("%d\n",(int)toShow.size());
            for(auto va:toShow)
                printf("%d ",va-(int)b.size());
            puts("");
        }
    }
    return 0;
}
