#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    while(n--){
        char pos[130];
        scanf(" %s",pos);
        vector<char> st;
        bool posi = 1;
        int i = 0;
        for(; i < 130 && posi && pos[i] != '\0';++i){
            if(pos[i] == ')'){
                if(st.back() != '(') posi =0;
                else st.pop_back();
            }
            else if(pos[i] == ']'){
                if(st.back() != '[')posi = 0;
                else st.pop_back();
            }
            else
                st.push_back(pos[i]);
        }
        if(!posi || st.size()) puts("No");
        else puts("Yes");
    }
    return 0;
}
