#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool z_function(vector<int> &s, int tama){
	int n = (int) s.size();
	vector<int> z(n);
	for(int i=1,l=0,r=0; i<n; i++){
		if(i<=r)
			z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<n && s[z[i]]==s[i+z[i]])
			++z[i];
		if(i+z[i]-1>r)
			l=i,r=i+z[i]-1;
	}
	for(int i = tama+1; i < z.size();++i)
        if(z[i] == tama) return 1;
    return 0;
}


int main(){
    int n;
    scanf(" %d",&n);
    vector<int> aut(n);
    vector<int> rev(n);
    for(int i = 0; i < n;++i){
        scanf(" %d",&aut[i]);
        rev[i] = aut[i];
        aut.push_back(aut[i]);
        rev.push_back(rev[i]);
    }
    reverse(rev.begin(),rev.end());
    vector<int> see1(n);
    vector<int> see2(n);
    for(int i = 0; i < n;++i){
        scanf(" %d",&see1[i]);
        see2[i] = see1[i];
    }
    see1.push_back(-1);
    see2.push_back(-1);
    for(int i = 0; i < aut.size();++i){
        see1.push_back(aut[i]);
        see2.push_back(rev[i]);
    }
    bool ans = 0;
    ans = ans | z_function(see1,n);
    ans = ans | z_function(see2,n);
    if(ans)puts("YES");
    else puts("NO");
    return 0;
}
