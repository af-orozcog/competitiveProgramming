#include<bits/stdc++.h>
using namespace std;

vector<int> getZarr(string str,int siz) 
{ 
    int n = str.length(); 
    int L, R, k; 
    int Z[str.size()];
    vector<int> ans;
    L = R = 0; 
    for (int i = 1; i < n; ++i) 
    { 
        if (i > R) 
        { 
            L = R = i; 
            while (R<n && str[R-L] == str[R]) 
                R++; 
            Z[i] = R-L; 
            R--; 
        } 
        else
        { 
            k = i-L;
            if (Z[k] < R-i+1) 
                Z[i] = Z[k];  
            else
            { 
                L = i; 
                while (R<n && str[R-L] == str[R]) 
                    R++; 
                Z[i] = R-L; 
                R--; 
            } 
        }
        if(Z[i] == siz)
            ans.push_back(i-siz-1);
    }
    return ans;
} 

int main(){
    string pa,se;
    while(getline(cin,pa)){
        getline(cin,se);
        string send = pa + "?" +se;
        vector<int> ans = getZarr(send,pa.size());
        for(int i = 0; i < ans.size();++i){
            if(i)
                printf(" %d",ans[i]);
            else
                printf("%d",ans[i]);
        }
        puts("");
    }
    return 0;
}