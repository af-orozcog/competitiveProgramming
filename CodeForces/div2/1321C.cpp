#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string re;
    cin >> n >> re;
    bool keep = 1;
    while(keep){
        vector<int> marked(re.size(),0);
        for(int i = 1; i < re.size();++i){
            if(re[i-1] == re[i]-1)
                ++marked[i];
        }
        for(int i = 0; i < (int)re.size()-1;++i){
            if(re[i]-1 == re[i+1])
                ++marked[i];
        }
        string neRe = "";
        keep = 0;
        for(int i = 0; i < re.size();++i){
            if(marked[i] == 0) neRe += re[i];
            else if(marked[i] == 2) keep = 1;
            else keep = 1;
        }
        re = neRe;
    }
    cout << re << endl;
    printf("%d\n",n - (int)re.size());
    return 0;
}
